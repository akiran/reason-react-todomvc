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
            onClick={(e) => selectFilter(ALL: TodoData.filter)}
          >
            {"All" -> React.string}
          </a>
        </li>
        <li>
          <a
            href="#/"
            onClick={(e) => selectFilter(ACTIVE: TodoData.filter)}
          >
            {"Active" -> React.string}
          </a>
        </li>
        <li>
          <a
            href="#/"
            onClick={(e) => selectFilter(COMPLETED: TodoData.filter)}
          >
            {"COMPLETED" -> React.string}
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