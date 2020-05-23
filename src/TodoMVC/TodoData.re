type todo = {
  id: string,
  title: string,
  completed: bool
}

type todos = array(todo)

type filter = ALL | ACTIVE | COMPLETED;

type action =
  | ADD_TODO(string)

type state = {
  todos: todos,
  filter: filter
}


