
[@react.component]
let make = (~addTodo) => {
  let (title, setTitle) = React.useState(() => "");
  let handleKeyDown = (e) => {
    if (ReactEvent.Keyboard.key(e) === "Enter") {
      addTodo(title)
      setTitle((title) => "")
    }
  };

  <input
    className="new-todo"
    placeholder="what needs to be done?"
    value={title}
    onChange={(e) => setTitle(ReactEvent.Form.target(e)##value)}
    onKeyDown={handleKeyDown}
  />
}
