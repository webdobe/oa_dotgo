<?php
/**
 * @file
 * Template for Open Atrium matchbox App.
 * $link - link for full matchbox
 * $search - search dropdown list
 * $data - JSON data
 */
?>
<div class="oa-matchbox" ng-cloak ng-app="oamatchbox" ng-controller="oamatchboxController" ondragstart="return false;" ondrop="return false;">
  <div class="oa-matchbox-header clearfix">
    <div class="oa-matchbox-search btn-group">
      <button class="oa-matchbox-search-toggle btn btn-default dropdown-toggle" data-toggle="dropdown" href="#">{{matches[currentSlide].title}} <span class="caret"></span></button>
      <ul class="dropdown-menu" role="menu">
        <li ng-repeat="dropDownSelect in dropDownSelects">
          <a ng-class="dropDownSelect.classes" class="oa-matchbox-search-link" ng-click="exploreMatch(dropDownSelect.nid, 1)">{{dropDownSelect.prefix}}{{dropDownSelect.title}}</a>
        </li>
      </ul>
    </div>
    <a class="btn-none pull-right" ng-if="showHelp && helpStatus" ng-click="toggleHelp(false)" href="#">
      Hide Help
    </a>
    <a class="btn btn-default pull-right" ng-if="showHelp && !helpStatus" ng-click="toggleHelp(true)" href="#">
      <i class="icon-question-sign"></i> Help
    </a>
  </div>
  <div class="oa-matchbox-help row" ng-if="showHelp && helpStatus && match.new_match">
    <img class="oa-matchbox-helpimage" ng-src="{{basePath}}/images/atrium-tree.png">
    <div class="oa-matchbox-matchhelp" ng-if="!match.new_section">
      <img class="pull-left oa-matchbox-helpicon" ng-src="{{basePath}}/images/match.png">
      <div ng-bind-html="matchHelp"></div>
    </div>
    <div class="oa-matchbox-caret">
      <img ng-src="{{basePath}}/images/triangle.png">
    </div>
  </div>
  <div class="oa-matchbox-container row">
    <div class="oa-matchbox-builder col-md-9">
      <ul class="oa-matchbox-breadcrumbs">
        <li class="oa-matchbox-breadcrumb" ng-repeat="breadcrumb in breadcrumbs.slice().reverse()">
          <a class="btn btn-default" ng-click='exploreMatch(breadcrumb.nid, -1)' ng-drop="true" ng-drop-success="onDropOnMatch($data,breadcrumb.nid,$event)">{{breadcrumb.title}}</a>
        </li>
      </ul>
      <div id="oa-matchbox-top" class="oa-carousel-container">
        <div class="oa-match-header">
          <button class="prev" ng-show="matches[currentSlide-1]" ng-click="slide(currentSlide-1)" ng-drop="true" ng-drop-success="onDropOnMatch($data,matches[currentSlide-1].nid,$event)">{{matches[currentSlide - 1].title}}</button>
          <div class="dropdown">
            <a class="oa-match-title" data-toggle="dropdown" href="#" ng-drop="true">{{matches[currentSlide].title}}</a>
            <ul class="dropdown-menu" role="menu">
              <li ng-repeat="match in matches">
                <a ng-click="slide($index)" ng-drop="true" ng-drop-success="onDropOnMatch($data,match.nid,$event)">{{match.title}}</a>
              </li>
            </ul>
            <a ng-href="{{matches[currentSlide].url}}">
              &nbsp;&nbsp;<i class="icon-eye-open"></i>
            </a>
          </div>
          <button class="next" ng-show="matches[currentSlide+1]" ng-click="slide(currentSlide+1)" ng-drop="true" ng-drop-success="onDropOnMatch($data,matches[currentSlide+1].nid,$event)">{{matches[currentSlide + 1].title}}</button>
        </div>
        <div class="oa-matches">
          <section class="oa-submatches">
            <div class="oa-submatch" ng-repeat="index in match.submatches" ng-drag="{{dragDrop}}" ng-drag-data="allMatches[index]" ng-drag-id="2">
              <div class="oa-submatch-icons" ng-hide="allMatches[index].editorEnabled">
                <div class="oa-submatch-icon-left">
                  <a ng-href="{{allMatches[index].url}}">
                    <i class="icon-user {{matchClass(index)}}"></i>
                  </a>
                </div>
                <div ng-show="allMatches[index].admin" class="dropdown oa-submatch-icon-center">
                  <a class="" data-toggle="dropdown" href="#"><i class="icon-cog"></i></a>
                  <ul class="dropdown-menu" role="menu">
                    <li><a ng-href="{{editURL(allMatches[index])}}">Edit</a></li>
                    <li><a ng-click="deleteSubmatch(match, index)">Delete</a></li>
                    <li><a ng-click="enableEditor(allMatches[index])">Rename</a></li>
                  </ul>
                </div>
                <div class="oa-submatch-icon-right">
                  <a ng-href="{{allMatches[index].url}}">
                    <i class="icon-eye-open"></i>
                  </a>
                </div>
              </div>
              <h4 class="oa-submatch-title">
                <a ng-hide="allMatches[index].editorEnabled" class="oa-submatch-link" ng-click='exploreMatch($parent.allMatches[index].nid, 1)'
                   ng-drop="true" ng-drop-success="onDropOnMatchWeight($data,index,$event)">
                  <span>{{$parent.allMatches[index].title}}</span>
                </a>
                <div ng-show="allMatches[index].editorEnabled">
                  <textarea ng-model="editableTitle[index]"></textarea>
                  <div class="oa-rename-actions">
                    <a href="#" ng-click="saveTitle(allMatches[index])">Save</a>
                    or
                    <a href="#" ng-click="disableEditor(allMatches[index])">Cancel</a>.
                  </div>
                </div>
              </h4>
            </div>
            <div ng-if="match.new_match" class="oa-submatch oa-new-match">
              <h4 class="oa-submatch-title">
                <a ng-href="{{newMatchURL(match.nid)}}" ng-class="newMatchClass(match.nid)" title="{{newMatchTitle(match.nid)}}"
                   ng-drop="true" ng-drop-id="[2]" ng-drop-success="onDropOnMatchClone($data,match.submatches.length,-1,$event)">
                  <span><i class="icon-plus"></i>{{newMatchTitle(match.nid)}}</span>
                </a>
              </h4>
            </div>
          </section>
        </div>
      </div>
      <ul class="oa-matchbox-trailcrumbs">
        <li class="oa-matchbox-trailcrumb" ng-repeat="trailcrumb in trailcrumbs.slice()">
          <a class="btn btn-default" ng-click='exploreMatch(trailcrumb.nid, 1)' ng-drop="true" ng-drop-success="onDropOnMatch($data,trailcrumb.nid,$event)">{{trailcrumb.title}}</a>
        </li>
      </ul>
    </div>
    <div class="oa-matchbox-stream col-md-3">
      <ul class="oa-matchbox-messages">
        <li class="oa-matchbox-message" ng-repeat="message in messages.slice().reverse()">
          <a class="message-init" ng-click='exploreMatch(message.nid, -1)' ng-drop="true" ng-drop-success="onDropOnMatch($data,message.nid,$event)">
            <div class="popover left">
              <div class="arrow"></div>
              <div class="popover-content" ng-bind-html="message.user_message">
              </div>
            </div>
          </a>
          <a class="message-responses" ng-repeat="response in message.dotgo_messages.slice()" ng-click='exploreMatch(message.nid, -1)' ng-drop="true" ng-drop-success="onDropOnMatch($data,message.nid,$event)">
            <div class="popover right">
              <div class="arrow"></div>
              <div class="popover-content" ng-bind-html="response">
              </div>
            </div>
          </a>
        </li>
      </ul>
    </div>
  </div>
  <div id="oa-matchbox-footer">
    <a class="btn-none pull-right" ng-if="match.new_match && dragDrop" ng-click="toggleDrag(false)" href="#">
      Disable Drag/drop
    </a>
    <a class="btn-none pull-right" ng-if="match.new_match && !dragDrop" ng-click="toggleDrag(true)" href="#">
      Enable Drag/drop
    </a>
  </div>
</div>
