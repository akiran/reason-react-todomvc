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
  switch(action) {
    | ADD_TODO(title) => {...state, todos: Belt.Array.concat(
        state.todos, [|{id: "10", title, completed: false}|]
      )}
  }
};

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  let currentTodos = filterTodos(state.todos, state.filter);

  <section className="todoapp">
    <header className="header">
      <h1>{React.string("todos")}</h1>
      <TodoInput addTodo={(title) => dispatch(ADD_TODO(title))} />
    </header>
    <TodoList todos={currentTodos} />
    <TodoFooter activeTodoCount={2} />
  </section>
}
