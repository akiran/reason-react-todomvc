[@react.component]
let make = (~activeTodoCount, ~completedCount, ~clearCompleted, ~filter, ~selectFilter) => {
  let countText = " " ++ (activeTodoCount === 1 ? "item" : "items") ++ " left";

  <footer className="footer">
      <span className="todo-count">
        <strong>{activeTodoCount -> React.int}</strong>
        {countText -> React.string}
      </span>
      <ul className="filters">
        <li>
          <a
            href="#/"
            onClick={(e) => selectFilter(TodoData.ALL)}
            className={filter === TodoData.ALL ? "selected": ""}
          >
            {"All" -> React.string}
          </a>
        </li>
        <li>
          <a
            href="#/"
            onClick={(e) => selectFilter(TodoData.ACTIVE)}
            className={filter === TodoData.ACTIVE ? "selected": ""}
          >
            {"Active" -> React.string}
          </a>
        </li>
        <li>
          <a
            href="#/"
            onClick={(e) => selectFilter(TodoData.COMPLETED)}
            className={filter === TodoData.COMPLETED ? "selected": ""}
          >
            {"Completed" -> React.string}
          </a>
        </li>
      </ul>
      {completedCount > 0 ? (
        <button className="clear-completed" onClick={clearCompleted}>
          {"Clear completed " -> React.string}
        </button>
      ): React.null}
  </footer>
}