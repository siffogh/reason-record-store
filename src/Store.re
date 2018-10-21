let component = ReasonReact.statelessComponent("Store");
let renderAlbumRow = (album: Utils.album, buyAlbum) =>
  <tr key={album.name}>
    <td> {album.name |> ReasonReact.string} </td>
    <td> {album.artist |> ReasonReact.string} </td>
    <td> {album.count |> string_of_int |> ReasonReact.string} </td>
    <td>
      <button onClick={_ => buyAlbum(album)} disabled={album.count == 0}>
        {(album.count == 0 ? "sold out" : "add to cart") |> ReasonReact.string}
      </button>
    </td>
  </tr>;

let make = (~albums, ~buyAlbum, _children) => {
  ...component,
  render: _ =>
    <div>
      <h2> {"Store" |> ReasonReact.string} </h2>
      <table>
        <thead>
          <tr>
            <th> {"Name" |> ReasonReact.string} </th>
            <th> {"Artist" |> ReasonReact.string} </th>
            <th> {"Stock" |> ReasonReact.string} </th>
            <th />
          </tr>
        </thead>
        <tbody>
          {
            List.map(album => renderAlbumRow(album, buyAlbum), albums)
            |> Array.of_list
            |> ReasonReact.array
          }
        </tbody>
      </table>
    </div>,
};