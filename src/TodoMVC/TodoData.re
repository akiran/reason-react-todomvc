type todo = {
  id: string,
  title: string,
  completed: bool
}

type todos = array(todo)

type filter = ALL | ACTIVE | COMPLETED