open TodoData;

[@react.component]
let make = (~activeTodoCount, ~completedCount, ~clearCompleted, ~activeFilter, ~selectFilter) => {
  let countText = " " ++ (activeTodoCount === 1 ? "item" : "items") ++ " left";

  <footer className="footer">
      <span className="todo-count">
        <strong>{activeTodoCount -> React.int}</strong>
        {countText -> React.string}
      </span>
      <ul className="filters">
        <TodoFilter
          activeFilter={activeFilter}
          filter={ALL}
          selectFilter={selectFilter}
        />
        <TodoFilter
          activeFilter={activeFilter}
          filter={ACTIVE}
          selectFilter={selectFilter}
        />
        <TodoFilter
          activeFilter={activeFilter}
          filter={COMPLETED}
          selectFilter={selectFilter}
        />
      </ul>
      {completedCount > 0 ? (
        <button className="clear-completed" onClick={clearCompleted}>
          {"Clear completed " -> React.string}
        </button>
      ): React.null}
  </footer>
};





