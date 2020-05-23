[@react.component]
let make = (~activeTodoCount) => {
  let countText = " " ++ (activeTodoCount === 1 ? "item" : "items") ++ " left";

  <footer className="footer">
      <span className="todo-count">
        <strong>{activeTodoCount -> React.int}</strong>
        {countText -> React.string}
      </span>
  </footer>
}