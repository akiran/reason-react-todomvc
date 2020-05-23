
type todo = {
  id: string,
  title: string,
  completed: bool
}

let todos = [|
  {id: "1", title: "learn reason", completed: false},
  {id: "2", title: "learn react", completed: true}
|];


[@react.component]
let make = () => {
  <div>
    {React.string("hello")}
    {
      todos
      ->Belt.Array.mapWithIndex((i, todo) => {
        <div key={string_of_int(i)}>{React.string(todo.title)}</div>
      })
      ->React.array
    }
  </div>
}