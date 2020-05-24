[@react.component]
let make = (~activeTodoCount, ~completedCount, ~clearCompleted) => {
  let countText = " " ++ (activeTodoCount === 1 ? "item" : "items") ++ " left";

  <footer className="footer">
      <span className="todo-count">
        <strong>{activeTodoCount -> React.int}</strong>
        {countText -> React.string}
      </span>
      {completedCount > 0 ? (
        <button className="clear-completed" onClick={clearCompleted}>
          {"Clear completed " -> React.string}
        </button>
      ): React.null}
  </footer>
}