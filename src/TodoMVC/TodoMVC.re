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


let reducer = (todos: TodoData.todos, action: TodoData.todoAction) => {
  let activeTodos = Belt.Array.keep(todos, todo => todo.completed)
  let activeTodoCount = Belt.Array.length(activeTodos)
  let todoCount = Belt.Array.length(todos)
  switch(action) {
    | ADD_TODO(title) => Belt.Array.concat(todos, [|{id: "10", title, completed:false}|])
    | DELETE_TODO(id) => Belt.Array.keep(todos, todo => todo.id != id)
    | TOGGLE_TODO(id) => Belt.Array.map(
        todos,
        todo => todo.id == id ? {...todo, completed: !todo.completed}: todo
      )
    | TOGGLE_ALL => Belt.Array.map(
        todos,
        todo => {...todo, completed: !(activeTodoCount === todoCount)}
      )
  }
};

[@react.component]
let make = () => {
  let (todos, dispatch) = React.useReducer(reducer, initialTodos);
  let (filter, setFilter) = React.useState(():TodoData.filter => ALL)

  let activeTodos = Belt.Array.keep(todos, todo => todo.completed)
  let activeTodoCount = Belt.Array.length(activeTodos)

  let currentTodos = filterTodos(todos, filter);

  let addTodo = title => dispatch(ADD_TODO(title));
  let deleteTodo = id => dispatch(DELETE_TODO(id));
  let toggleTodo = id => dispatch(TOGGLE_TODO(id));
  let toggleAll = (e) => dispatch(TOGGLE_ALL);

  <section className="todoapp">
    <header className="header">
      <h1>{React.string("todos")}</h1>
      <TodoInput addTodo={addTodo} />
    </header>
    <TodoList
      todos={currentTodos}
      deleteTodo={deleteTodo}
      toggleTodo={toggleTodo}
      toggleAll={toggleAll}
      activeTodoCount={activeTodoCount}
    />
    <TodoFooter activeTodoCount={activeTodoCount} />
  </section>
}
