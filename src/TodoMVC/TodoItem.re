[@react.component]
let make = (~todo: TodoData.todo) => {
  let onToggle = (e) => ();

  <li>
    <div className="view">
      <input
          className="toggle"
          type_="checkbox"
          checked={todo.completed}
          onChange={onToggle}
        />
      <label>{todo.title -> React.string}</label>
    </div>
  </li>
}