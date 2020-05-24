open TodoData;

[@react.component]
let make = (~todo, ~onDelete, ~onToggle) => {

  <li className={todo.completed ? "completed" : ""}>
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