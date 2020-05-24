
[@react.component]
let make = (~todos: TodoData.todos, ~deleteTodo, ~toggleTodo, ~toggleAll, ~activeTodoCount) => {
  <section className="main">
   <input
      id="toggle-all"
      className="toggle-all"
      type_="checkbox"
      onChange={toggleAll}
      checked={activeTodoCount === 0}
    />
    <label htmlFor="toggle-all" />
    <ul className="todo-list">
      {
        todos
        ->Belt.Array.map(todo => {
          <TodoItem
            todo key={todo.id}
            onDelete={(_) => deleteTodo(todo.id)}
            onToggle={(_) => toggleTodo(todo.id)}
          />
        })
        ->React.array
      }
    </ul>
  </section>
}