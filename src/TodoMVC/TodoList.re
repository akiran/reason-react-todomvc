
[@react.component]
let make = (~todos: TodoData.todos) => {
  <section className="main">
    <ul className="todo-list">
      {
        todos
        ->Belt.Array.map(todo => {
          <TodoItem todo key={todo.id} />
        })
        ->React.array
      }
    </ul>
  </section>
}