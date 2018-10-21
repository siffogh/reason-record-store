let albumsData = [
  {Utils.name: "Drip Harder", artist: "Lil Baby & Gunna", count: 10},
  {name: "Scorpion", artist: "Drake", count: 10},
  {name: "ASTROWORLD", artist: "Travis Scott", count: 10},
  {name: "Beerbongs & Bentleys", artist: "Post Malone", count: 10},
  {name: "Kamikazer", artist: "Eminem", count: 10},
  {name: "Luca Brasi 3", artist: "Kevin Gates", count: 10},
  {name: "Dime Trap", artist: "T.I", count: 10},
  {name: "?", artist: "XXXTENTACION", count: 10},
  {name: "Queen", artist: "Nicki Minaj", count: 10},
  {name: "Invasion Of Privacy", artist: "Cardi B", count: 10},
];

type state = {
  availableAlbums: list(Utils.album),
  albumsInBasket: list(Utils.album),
};

type action =
  | ADD_TO_BASKET(Utils.album)
  | REMOVE_FROM_BASKET(Utils.album);

/* This is the basic component. */
let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,

  initialState: () => {availableAlbums: albumsData, albumsInBasket: []},

  reducer: (action, state) =>
    switch (action) {
    | ADD_TO_BASKET({name, artist}) =>
      let availableAlbums =
        List.map(
          (album: Utils.album) =>
            if (album.name == name) {
              {...album, count: album.count - 1};
            } else {
              album;
            },
          state.availableAlbums,
        );

      let albumsInBasket =
        switch (
          state.albumsInBasket
          |> List.find(album => (album: Utils.album).name == name)
        ) {
        | _ =>
          state.albumsInBasket
          |> List.map(album =>
               (album: Utils.album).name == name ?
                 {...album, count: album.count + 1} : album
             )
        | exception Not_found => [
            {name, artist, count: 1},
            ...state.albumsInBasket,
          ]
        };

      ReasonReact.Update({availableAlbums, albumsInBasket});
    | REMOVE_FROM_BASKET({name, artist}) =>
      let availableAlbums =
        List.map(
          (album: Utils.album) =>
            if (album.name == name) {
              {...album, count: album.count + 1};
            } else {
              album;
            },
          state.availableAlbums,
        );

      let albumsInBasket =
        switch (
          state.albumsInBasket
          |> List.find(album => (album: Utils.album).name == name)
        ) {
        | _ =>
          state.albumsInBasket
          |> List.map(album =>
               (album: Utils.album).name == name ?
                 {...album, count: album.count - 1} : album
             )
          |> List.filter(album => (album: Utils.album).count > 0)
        | exception Not_found => [
            {name, artist, count: 1},
            ...state.albumsInBasket,
          ]
        };

      ReasonReact.Update({availableAlbums, albumsInBasket});
    },

  render: self =>
    <div className="app">
      <Store
        albums={self.state.availableAlbums}
        buyAlbum={album => self.send(ADD_TO_BASKET(album))}
      />
      <Basket
        albums={self.state.albumsInBasket}
        removeAlbum={album => self.send(REMOVE_FROM_BASKET(album))}
      />
    </div>,
};