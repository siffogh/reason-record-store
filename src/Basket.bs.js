// Generated by BUCKLESCRIPT VERSION 4.0.6, PLEASE EDIT WITH CARE

import * as List from "bs-platform/lib/es6/list.js";
import * as $$Array from "bs-platform/lib/es6/array.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as ReasonReact from "reason-react/src/ReasonReact.js";

var component = ReasonReact.statelessComponent("Basket");

function renderUtilsRow(album, removeAlbum) {
  return React.createElement("tr", {
              key: album[/* name */0]
            }, React.createElement("td", undefined, album[/* name */0]), React.createElement("td", undefined, album[/* artist */1]), React.createElement("td", undefined, String(album[/* count */2])), React.createElement("td", undefined, React.createElement("button", {
                      onClick: (function () {
                          return Curry._1(removeAlbum, album);
                        })
                    }, "remove")));
}

function make(albums, removeAlbum, _) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function () {
              var match = List.length(albums) === 0;
              return React.createElement("div", undefined, React.createElement("h2", undefined, "Shopping Basket"), match ? React.createElement("div", undefined, "Add an item to the basket") : React.createElement("table", undefined, React.createElement("thead", undefined, React.createElement("tr", undefined, React.createElement("th", undefined, "Name"), React.createElement("th", undefined, "Artist"), React.createElement("th", undefined, "Count"), React.createElement("th", undefined))), React.createElement("tbody", undefined, $$Array.of_list(List.map((function (album) {
                                              return renderUtilsRow(album, removeAlbum);
                                            }), albums)))));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

export {
  component ,
  renderUtilsRow ,
  make ,
  
}
/* component Not a pure module */
