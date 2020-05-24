open TodoData;

let filterText = (filter) => {
  switch(filter) {
    | ALL => "All"
    | ACTIVE => "Active"
    | COMPLETED => "Completed"
  }
};

[@react.component]
let make = (~activeFilter, ~filter, ~selectFilter) => {
  <li>
    <a
      href="#/"
      onClick={(_) => selectFilter(filter)}
      className={activeFilter === filter ? "selected": ""}
    >
      {React.string(filterText(filter))}
    </a>
  </li>
};