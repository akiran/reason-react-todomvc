type todo = {
  id: string,
  title: string,
  completed: bool
}

type todos = array(todo)

type filter = ALL | ACTIVE | COMPLETED;

type action =
  | ADD_TODO(string)
  | DELETE_TODO(string)
  | TOGGLE_TODO(string)
  | TOGGLE_ALL

type state = {
  todos: todos,
  filter: filter
}


