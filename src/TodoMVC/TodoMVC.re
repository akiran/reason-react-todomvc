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

let initialState: TodoData.state = {todos: initialTodos, filter: ALL};

let reducer = (state:TodoData.state, action: TodoData.action) => {
  let activeTodos = Belt.Array.keep(state.todos, todo => todo.completed)
  let activeTodoCount = Belt.Array.length(activeTodos)
  let todoCount = Belt.Array.length(state.todos)
  switch(action) {
    | ADD_TODO(title) => {
        ...state,
        todos: Belt.Array.concat(state.todos, [|{id: "10", title, completed:false}|]
      )}
    | DELETE_TODO(id) => {
        ...state,
        todos: Belt.Array.keep(state.todos, todo => todo.id != id)
      }
    | TOGGLE_TODO(id) => {
      ...state,
      todos: Belt.Array.map(
        state.todos,
        todo => todo.id == id ? {...todo, completed: !todo.completed}: todo
      )
    }
    | TOGGLE_ALL => {
      ...state,
      todos: Belt.Array.map(
        state.todos,
        todo => {...todo, completed: !(activeTodoCount === todoCount)}
      )
    }
  }
};

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  let activeTodos = Belt.Array.keep(state.todos, todo => todo.completed)
  let activeTodoCount = Belt.Array.length(activeTodos)

  let currentTodos = filterTodos(state.todos, state.filter);

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
