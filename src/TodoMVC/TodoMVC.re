
[@react.component]
let make = () => {
  <section className="todoapp">
    <header className="header">
      <h1>{React.string("todos")}</h1>
      <TodoInput />
    </header>
    <TodoList />
  </section>
}
