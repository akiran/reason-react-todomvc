
let initialTodos: TodoData.todos = [|
  {id: "1", title: "learn reason", completed: false},
  {id: "2", title: "learn react", completed: true}
|];


let filterTodos = (todos: TodoData.todos, nowShowing: TodoData.filter) => {
  switch(nowShowing) {
    | ALL => todos
    | ACTIVE => Belt.Array.keep(todos, todo => !todo.completed)
    | COMPLETED => Belt.Array.keep(todos, todo => todo.completed)
  }
};

[@react.component]
let make = () => {
  let (todos, setTodos) = React.useState(() => initialTodos);
  let (nowShowing, setFilter) = React.useState((): TodoData.filter => ALL);

  let currentTodos = filterTodos(todos, nowShowing);

  <section className="todoapp">
    <header className="header">
      <h1>{React.string("todos")}</h1>
      <TodoInput />
    </header>
    <TodoList todos={currentTodos} />
    <TodoFooter activeTodoCount={2} />
  </section>
}
