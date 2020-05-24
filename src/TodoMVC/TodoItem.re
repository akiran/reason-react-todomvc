[@react.component]
let make = (~todo: TodoData.todo, ~onDelete, ~onToggle) => {

  <li>
    <div className="view">
      <input
          className="toggle"
          type_="checkbox"
          checked={todo.completed}
          onChange={onToggle}
        />
      <label>{todo.title -> React.string}</label>
      <button className="destroy" onClick={onDelete} />
    </div>
  </li>
}