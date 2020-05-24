
[@react.component]
let make = (~todos: TodoData.todos, ~deleteTodo) => {
  <section className="main">
    <ul className="todo-list">
      {
        todos
        ->Belt.Array.map(todo => {
          <TodoItem todo key={todo.id} onDelete={(e) => deleteTodo(todo.id)} />
        })
        ->React.array
      }
    </ul>
  </section>
}