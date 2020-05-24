type todo = {
  id: string,
  title: string,
  completed: bool
}

type todos = array(todo)

type filter = ALL | ACTIVE | COMPLETED;

type todoAction =
  | ADD_TODO(string)
  | DELETE_TODO(string)
  | TOGGLE_TODO(string)
  | TOGGLE_ALL
  | CLEAR_COMPLETED



