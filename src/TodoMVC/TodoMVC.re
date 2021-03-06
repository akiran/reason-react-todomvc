open TodoData;

let initialTodos = [|
  {id: Uuid.V4.uuidv4(), title: "learn reason", completed: false},
  {id: Uuid.V4.uuidv4(), title: "learn react", completed: true}
|];

let filterTodos = (todos, filter) => {
  switch(filter) {
    | ALL => todos
    | ACTIVE => Belt.Array.keep(todos, todo => !todo.completed)
    | COMPLETED => Belt.Array.keep(todos, todo => todo.completed)
  }
};


let reducer = (todos, action) => {
  let activeTodos = Belt.Array.keep(todos, todo => todo.completed)
  let activeTodoCount = Belt.Array.length(activeTodos)
  let todoCount = Belt.Array.length(todos)
  switch(action) {
    | ADD_TODO(title) => Belt.Array.concat(todos, [|{id: Uuid.V4.uuidv4(), title, completed:false}|])
    | DELETE_TODO(id) => Belt.Array.keep(todos, todo => todo.id != id)
    | TOGGLE_TODO(id) => Belt.Array.map(
        todos,
        todo => todo.id == id ? {...todo, completed: !todo.completed}: todo
      )
    | TOGGLE_ALL => Belt.Array.map(
        todos,
        todo => {...todo, completed: !(activeTodoCount === todoCount)}
      )
    | CLEAR_COMPLETED => Belt.Array.keep(todos, todo => !todo.completed)
  }
};

[@react.component]
let make = () => {
  let (todos, dispatch) = React.useReducer(reducer, initialTodos)
  let (activeFilter, setFilter) = React.useState(() => ALL)

  let activeTodos = Belt.Array.keep(todos, todo => !todo.completed)
  let activeTodoCount = Belt.Array.length(activeTodos)
  let completedCount = Belt.Array.length(todos) - activeTodoCount

  let currentTodos = filterTodos(todos, activeFilter);

  let addTodo = title => dispatch(ADD_TODO(title));
  let deleteTodo = id => dispatch(DELETE_TODO(id));
  let toggleTodo = id => dispatch(TOGGLE_TODO(id));
  let toggleAll = (_) => dispatch(TOGGLE_ALL);
  let clearCompleted = (_) => dispatch(CLEAR_COMPLETED);
  let selectFilter = (filter) => setFilter((_) => filter);

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
    <TodoFooter
      activeTodoCount={activeTodoCount}
      completedCount={completedCount}
      clearCompleted={clearCompleted}
      selectFilter={selectFilter}
      activeFilter={activeFilter}
    />
  </section>
}
