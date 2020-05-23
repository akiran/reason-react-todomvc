
[@react.component]
let make = () => {
  let (title, setTitle) = React.useState(() => "one");
  let handleKeyDown = (e) => {
    if (ReactEvent.Keyboard.key(e) !== "Enter") {
      Js.log(title)
    } else {
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
