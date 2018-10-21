let component = ReasonReact.statelessComponent("Basket");
let renderUtilsRow = (album: Utils.album, removeAlbum) =>
  <tr key={album.name}>
    <td> {album.name |> ReasonReact.string} </td>
    <td> {album.artist |> ReasonReact.string} </td>
    <td> {album.count |> string_of_int |> ReasonReact.string} </td>
    <td>
      <button onClick={_ => removeAlbum(album)}>
        {"remove" |> ReasonReact.string}
      </button>
    </td>
  </tr>;

let make = (~albums, ~removeAlbum, _children) => {
  ...component,
  render: _ =>
    <div>
      <h2> {"Shopping Basket" |> ReasonReact.string} </h2>
      {
        List.length(albums) == 0 ?
          <div> {"Add an item to the basket" |> ReasonReact.string} </div> :
          <table>
            <thead>
              <tr>
                <th> {"Name" |> ReasonReact.string} </th>
                <th> {"Artist" |> ReasonReact.string} </th>
                <th> {"Count" |> ReasonReact.string} </th>
                <th />
              </tr>
            </thead>
            <tbody>
              {
                albums
                |> List.map(album => renderUtilsRow(album, removeAlbum))
                |> Array.of_list
                |> ReasonReact.array
              }
            </tbody>
          </table>
      }
    </div>,
};