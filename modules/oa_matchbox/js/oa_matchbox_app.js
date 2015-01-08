


/**
 * @file
 * Javascript for the OA matchbox.
 */

(function ($) {

  var app = angular.module("oamatchbox", ['ngSanitize', 'ngDraggable']);

  app.controller("oamatchboxController", function($scope, $timeout, $location) {

    var currentID = 0;
    var topID = 0;
    var lastID = 0;
    var allMatches = {};
    var orderMatches = {};
    var messages = [];
    var breadcrumbs = [];
    var trailcrumbs = [];

    function loadMatch(id) {
      currentID = id;
      var parentId = allMatches[id].parent_id;
      var currentMatches = [];

      // if ID has a valid parent match
      var parentMatch = allMatches[parentId];
      if (parentMatch) {
        for (var i in parentMatch.submatches) {
          var childMatch = allMatches[parentMatch.submatches[i]];
          currentMatches.push(childMatch);
        }
      }
      // if ID does not have a valid parent i.e. is top level match
      else {
        currentMatches.push(allMatches[id]);
      }
      allMatches[id].editorEnabled = false;

      // need to call CTools to get it to re-attach the modal popup behavior
      // to links *after* our match has been updated
      $timeout( function() {
        $location.hash('');
        $scope.$broadcast('oamatchboxRefresh', id);
      }, 10);

      return currentMatches;
    }

    var current = true;
    function loadMessages(id) {
      var parentId = allMatches[id].parent_id;

      if(current){
        messages.push(allMatches[id]);
        current = false;
      }
      if ((parentId != -1) && (parentId in allMatches)) {
        messages.push(allMatches[parentId]);
        loadMessages(parentId);
      }

      return messages;
    }

    function loadBreadCrumbs(id) {
      var parentId = allMatches[id].parent_id;

      if ((parentId != -1) && (parentId in allMatches)) {
        breadcrumbs.push(allMatches[parentId]);
        loadBreadCrumbs(parentId);
      }

      return breadcrumbs;
    }

    function loadTrailCrumbs(active, last) {
      trailcrumbs = [];

      function returnChildren(id, active, depth) {
        var submatches = allMatches[id].submatches;
        for (var i in submatches) {
          var matchID = submatches[i];
          trailcrumbs.push(allMatches[matchID]);
          if (allMatches[matchID].submatches.length >= 1) {
            var child = returnChildren(allMatches[matchID].nid, active, depth+1);
            if (child) {
              return child;
            }
          }
        }
        return false;
      }

      returnChildren(last, active, 1);
      return trailcrumbs;
    }

    function returnMatchPosition (matches, index) {
      for (var i in matches) {
        if (matches[i].nid == index) {
          return parseInt(i);
        }
      }
      return -1;
    }

    function returnDropDownSelects(active, top) {
      var dropDownSelects = [allMatches[top]];

      function returnChildren(id, active, depth) {
        var submatches = allMatches[id].submatches;
        for (var i in submatches) {
          var matchID = submatches[i];
          allMatches[matchID].prefix = '';//new Array(depth+1).join("- ");
          allMatches[matchID].classes = matchID == active ? 'active' : '';
          dropDownSelects.push(allMatches[matchID]);
          if (allMatches[matchID].submatches.length >= 1) {
            var child = returnChildren(allMatches[matchID].nid, active, depth+1);
            if (child) {
              return child;
            }
          }
        }
        return false;
      }
      returnChildren(top, active, 1);
      return dropDownSelects;
    }

    function getOptions(helpValue, dragValue) {
      var value = 0;
      if (helpValue) {
        value = value + 1;
      }
      if (dragValue) {
        value = value + 2;
      }
      return value;
    }

    $scope.$on('oamatchboxRefresh', function(event, e) {
      // need to reset ctools since it caches the previous href values on modal links
      $('a.ctools-use-modal').each(function() {
        // get link url without any query string
        var newurl = $(this).attr('href');
        var newlink = newurl.split('?')[0];
        // now need to remove previous ajax assigned to the old url
        for (var base in Drupal.ajax) {
          var link = base.split('?')[0];
          if (newlink == link) {
            //Drupal.ajax[base].url = newurl;
            //Drupal.ajax[base].element_settings.url = newurl;
            Drupal.ajax[base].options.url = newurl;
          }
        }
      });
      // ok, now reattach new ctools ajax to modals
      Drupal.attachBehaviors($('.oa-matchbox'));
    });

    topID = Drupal.settings.oa_matchbox.topID;
    allMatches = Drupal.settings.oa_matchbox.matches;
    orderMatches = returnDropDownSelects(topID, topID);
    //lastID = orderMatches[Object.keys(orderMatches)[Object.keys(orderMatches).length-2]].nid;

    $scope.allMatches = allMatches;
    $scope.matches = loadMatch(topID);
    $scope.topDropdown = (0 in allMatches) ? 0 : topID;
    $scope.dropDownSelects = returnDropDownSelects(topID, $scope.topDropdown);
    $scope.editableTitle = {};
    $scope.match = allMatches[topID];
    $scope.showHelp = Drupal.settings.oa_matchbox.showHelp;
    $scope.helpStatus = Drupal.settings.oa_matchbox.options & 0x01;
    $scope.dragDrop = Drupal.settings.oa_matchbox.options & 0x02;
    $scope.fullPage = Drupal.settings.oa_matchbox.fullPage;
    $scope.matchHelp = Drupal.settings.oa_matchbox.matchHelp;
    $scope.sectionHelp = Drupal.settings.oa_matchbox.sectionHelp;
    $scope.basePath = Drupal.settings.oa_matchbox.basePath;
    $scope.title = Drupal.settings.oa_matchbox.title;
    $scope.messages = loadMessages(topID);
    $scope.breadcrumbs = loadBreadCrumbs(topID);
    $scope.trailcrumbs = loadTrailCrumbs(topID, topID);
    $scope.icons = Drupal.settings.oa_matchbox.icons;
    $scope.currentSlide = returnMatchPosition($scope.matches, topID);

    $scope.exploreMatch = function(matchID, direction) {
      if (!allMatches[matchID].dragging) {
        current = true;
        messages = [];
        breadcrumbs = [];
        $scope.messages = loadMessages(matchID);
        $scope.breadcrumbs = loadBreadCrumbs(matchID);
        $scope.trailcrumbs = loadTrailCrumbs(topID, matchID);
        $scope.matches = loadMatch(matchID);
        $scope.currentSlide = returnMatchPosition($scope.matches, matchID);
        $scope.match = allMatches[matchID];
        $scope.dropDownSelects = returnDropDownSelects(topID, $scope.topDropdown);
        if (parseInt(direction) != 0) {
          $('#oa-matchbox-top').css({
            top: -20 * parseInt(direction)
          });
          $('#oa-matchbox-top').animate({
            top: 0
          }, 300);
        }

      }
    };

    $scope.slide = function(slide) {
      var diff = $scope.currentSlide - parseInt(slide);
      $scope.currentSlide = parseInt(slide);
      $scope.match = $scope.matches[$scope.currentSlide];
      var offset = -1000;
      if (diff < 0) {
        offset = 1000;
      }
      $('#oa-matchbox-top').css('overflow', 'hidden');
      $('#oa-matchbox-top .oa-matches').css({
        opacity: 1,
        left: offset
      });
      $('#oa-matchbox-top .oa-match-header').css({
        opacity: 1,
        left: offset
      });
      $('#oa-matchbox-top .oa-matches').animate({
        opacity: 1,
        left: 0
      }, 300);
      $('#oa-matchbox-top .oa-match-header').animate({
        opacity: 1,
        left: 0
      }, 300,
      function () {
        $('#oa-matchbox-top').css('overflow', 'visible');
      });
    };

    $scope.toggleHelp = function(value) {
      $scope.helpStatus = value;
      var arg = getOptions(value, $scope.dragDrop);
      // ajax callback to set drupal user session value
      $.get(Drupal.settings.basePath + 'api/oa/matchbox-option/' + arg, {token: Drupal.settings.oa_matchbox.option_token});
    };

    $scope.toggleDrag = function(value) {
      $scope.dragDrop = value;
      var arg = getOptions($scope.helpStatus, value);
      // ajax callback to set drupal user session value
      $.get(Drupal.settings.basePath + 'api/oa/matchbox-option/' + arg, {token: Drupal.settings.oa_matchbox.option_token});
    };

    $scope.matchClass = function(matchID) {
      var className = '';
      if (allMatches[matchID].status != 0) {
        className = (allMatches[matchID].visibility == 0) ? 'oa-icon-green' : 'oa-icon-red';
      }
      return className;
    };

    $scope.sectionClass = function(section) {
      var className = (section.visibility) ? 'oa-border-green' : 'oa-border-red';
      return className;
    };

    $scope.newMatchTitle = function(matchID) {
      return (allMatches[matchID].parent_id >= 0) ? Drupal.t('New Submatch') : Drupal.t('New Match');
    };

    $scope.newMatchClass = function(matchID) {
      return 'oa-submatch-link ctools-use-modal ctools-modal-oa-matchbox-match';
    };

    $scope.newMatchURL = function(matchID) {
      var url = Drupal.settings.basePath + 'api/oa_wizard/match-wizard';

      if (allMatches[matchID].parameters) {
        url += '?' + $.param(allMatches[matchID].parameters);
      }
      return url;
    };

    $scope.newSectionTitle = function(matchID) {
      return Drupal.t('New Section');
    };

    $scope.newSectionClass = function(matchID) {
      return 'oa-section-link ctools-use-modal ctools-modal-oa-matchbox-section';
    };

    $scope.newSectionURL = function(matchID) {
      var url = Drupal.settings.basePath + 'api/oa_wizard/section-wizard';
      if (matchID > 0) {
        url = url + '?og_group_ref=' + matchID;
      }
      return url;
    };

    $scope.deleteSubmatch = function(match, nid) {
      if ((allMatches[nid].sections.length > 0) || (allMatches[nid].submatches.length > 0)) {
        alert('Can only delete empty matches.');
        return;
      }
      if (confirm('Are you sure you wish to delete "' + allMatches[nid].title + '" ?')) {
        //TODO: drupal ajax callback to delete a node
        var index = match.submatches.indexOf(nid);
        $.post(
          // Callback URL.
          Drupal.settings.basePath + 'api/oa/matchbox-delete/' + nid,
          {token: Drupal.settings.oa_matchbox.node_tokens['node_' + nid]},
          function( result ) {
            if ((result.length > 0) && (result[1].command == 'alert')) {
              alert(result[1].text);
            }
            else {
              if (index > -1) {
                match.submatches.splice(index, 1);
              }
              delete allMatches.nid;
              $scope.$apply();
            }
        });
      }
    };

    $scope.deleteSection = function(match, section) {
      if (confirm('Are you sure you wish to delete "' + section.title + '" ?')) {
        //TODO: drupal ajax callback to delete a node
        var index = match.sections.indexOf(section);
        $.post(
          // Callback URL.
          Drupal.settings.basePath + 'api/oa/matchbox-delete/' + section.nid,
          {token: Drupal.settings.oa_matchbox.node_tokens['node_' + nid]},
          function( result ) {
            if ((result.length > 0) && (result[1].command == 'alert')) {
              alert(result[1].text);
            }
            else {
              if (index > -1) {
                match.sections.splice(index, 1);
              }
              $scope.$apply();
            }
          });
      }
    };

    $scope.enableEditor = function(node) {
      $scope.editableTitle[node.nid] = node.title;
      node.editorEnabled = true;
    };

    $scope.disableEditor = function(node) {
      node.editorEnabled = false;
    };

    $scope.saveTitle = function(node) {
      var oldTitle = node.title;
      node.title = $scope.editableTitle[node.nid];
      $scope.disableEditor(node);
      $.post(
        // Callback URL.
        Drupal.settings.basePath + 'api/oa/matchbox-update/' + node.nid,
        {'node': node, token: Drupal.settings.oa_matchbox.node_tokens['node_' + node.nid]},
      function( result ) {
        if ((result.length > 0) && (result[1].command == 'alert')) {
          // undo local change and report error
          node.title = oldTitle;
          $scope.$apply();
          alert(result[1].text);
        }
      });
    };

    $scope.editURL = function(node) {
      return node.url_edit + '?destination=' + document.URL;
    };

    $scope.onDropOnMatch = function(data, matchID, evt){
      if (data.nid != matchID) {
        // dropping a match or section on a match
        console.log("drop MATCHLIST " + matchID + " success, data:", data);
        console.log("drop MATCHLIST, event:", evt);
        var oldParent = data.parent_id;
        data.parent_id = matchID;
        $.post(
          // Callback URL.
          Drupal.settings.basePath + 'api/oa/matchbox-update/' + data.nid,
          {'node': data, token: Drupal.settings.oa_matchbox.node_tokens['node_' + data.nid]},
          function( result ) {
            if ((result.length > 0) && (result[0].command == 'redirect')) {
              window.location.href = result[0].url;
            }
            else if ((result.length > 0) && (result[1].command == 'alert')) {
              // failed, so undo
              data.parent_id = oldParent;
              $scope.$apply();
              alert(result[1].text);
            }
            else {
              if (data.type == 'dotgo_match') {
                var oldIndex = allMatches[oldParent].submatches.indexOf(data.nid);
                allMatches[oldParent].submatches.splice(oldIndex, 1);
                allMatches[matchID].submatches.push(data.nid);
              }
              else {
                var oldIndex = $scope.match.sections.indexOf(data);
                allMatches[$scope.match.nid].sections.splice(oldIndex, 1);
                allMatches[matchID].sections.push(data);
              }
              $scope.$apply();
            }
          });
      }
    };

    $scope.onDropOnMatchWeight = function(data, matchID, evt){
      if (data.nid != matchID) {
        // dropping a match or section on a match
        //console.log("drop MATCHWEIGHT " + matchID + " success, data:", data);
        //console.log("drop MATCHWEIGHT, event:", evt);
        var parent = data.parent_id;
        var other_node = allMatches[matchID];
        $.post(
          // Callback URL.
          Drupal.settings.basePath + 'api/oa/matchbox-update/' + data.nid,
          {'node': data, 'other_node': other_node, token: Drupal.settings.oa_matchbox.node_tokens['node_' + data.nid]},
          function( result ) {
            if ((result.length > 0) && (result[0].command == 'redirect')) {
              window.location.href = result[0].url;
            }
            else if ((result.length > 0) && (result[1].command == 'alert')) {
              // failed, so undo
              console.log('FAILURE!');
              /*
              data.parent_id = oldParent;
              $scope.$apply();
              alert(result[1].text);*/
            }
            else {
              if (data.type == 'dotgo_match') {
                var oldIndex = allMatches[parent].submatches.indexOf(data.nid);
                var newIndex = allMatches[parent].submatches.indexOf(other_node.nid);
                allMatches[parent].submatches[oldIndex] = other_node.nid;
                allMatches[other_node.nid].weight = oldIndex;

                allMatches[parent].submatches[newIndex] = data.nid;
                allMatches[data.nid].weight = newIndex;
              }
              $scope.$apply();
            }
          });
      }
    };

    $scope.onDropOnMatchClone = function(data, index, matchID, evt){
      if (data.nid != matchID) {
        // don't drop over itself
        console.log("drop MATCHCLONE " + matchID + " success, index: " + index + " data:", data);
        // reordering submatches
      }
    };

    $(document).on('oaWizardNew', function(event, node) {
      // respond to event message from submitting oa_wizard form
      switch (node.type) {
        case 'dotgo_match':
          var parentID = (node.field_dotgo_match_parent == undefined) ? 0 : node.field_dotgo_match_parent.und[Object.keys(node.field_dotgo_match_parent.und)[0]].target_id;
          //var parameters = (allMatches[parentID].parameters == undefined) ? 0 : allMatches[parentID].parameters;
          allMatches[node.nid] = {
            'nid': node.nid,
            'parent_id': parentID,
            'title': node.title,
            'type': 'dotgo_match',
            'status': node.status,
            'visibility': 1,
            'admin': allMatches[parentID].admin,
            'url': Drupal.settings.basePath + 'node/' + node.nid,
            'url_edit': Drupal.settings.basePath + 'node/' + node.nid + '/edit',
            //'parameters': parameters,
            'new_match': allMatches[parentID].new_match,
            //'sections': [],
            'submatches': []
          };
          //allMatches[parentID].new_match = false,
          allMatches[parentID].submatches.push(node.nid);
          $scope.exploreMatch(currentID, 0);
          $scope.$apply();
          break;
      }
    });

  });

  Drupal.behaviors.oamatchbox = {
    attach: function(context, settings) {
      if (settings.oa_matchbox.fullPage) {
        $('body').addClass('oa-matchbox-full');
      }
    }
  }

}(jQuery));
