ScheduleSQL

* License [![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](LICENSE)

* Build Status [![Build Status]()]()

* Tests ![Tests]()




Introduction
-------------

ScheduleSQL is a C program and reproduces SQL commands using arguments.

Something about it:

* Written in C, ScheduleSQL is faster and stable.
* Having a friendly structure, it's easy to contribute to it.

# Script flags

| Script flags | Description                                                                           |
| ------------ | ------------------------------------------------------------------------------------- |
| -c           | Will create database file                               |
| -d           | Delete data                                                                      |
| -m           | Modify data                                                                 |
| -t           | Set target                           | |
| -mc          | Modify content
| -ac          | Add content |
| -dc          | Delete content
| -lc          | Location of content

### Example:

| Instruction                        | Arguments                        |
| --------------------------------  | --------------------------------------------------   |
| Create database                   | ``-c ScheduleSQL.json -t "~/my/database/folder"``  |
| Delete database                   | ``-d ScheduleSQL.json -t "~/my/database/folder"``  |
| Modify data of specific database  | ``-m ScheduleSQL.json -t "~/my/database/folder" -lc "\students\name\" -mc "Andrei"`` |

## Syntax Arguments

``-<type of action> <name of database> -<instruction flag> <location database> -<interaction flag> <location 1> <location 2> <location 3>``



| Type of action | Instruction flag | Interaction flag |
| :---: | :---: | :---: |
| -c | -t | -ac 
| -d |    | -mc
| -m |    | -dc
|    |    | -lc

**Type of action** flag is a mandatory flag. This flag is used to know what we want to do:
 * If we want to create a database, we will use `-c` argument.
 * If we want to delete a database, we will use `-d` argument.
 * If we want to modify a database, we will use `-m` argument.

**Instruction** flag is a mandatory flag. This flag is used, for now, only to get target/folder location of database.

**Interaction** flag is mandatory. With this flag we set action of interaction
 * It can be `add/modify/delete` content using: `-ad / -mc / -dc`
 * About them:
    - If we use `-ac`, key `<location 2>`, `<location 3>` is useless. If we use `<location 2>`, it will be ignored. If not, we will add content to entry from `-lc` and data from `<location 1>`
    - If we use `-mc`, key `<location 2>` is optional. We use `-mc` when we want to modify content of actual structure, searching data from `<location 1>`, using `<location 2>`. If it exist, we will modify `-lc` with argument `<location 2>` using data of `<location 3>`.
    - If we use `-dc`, key `<location 2>`, `<locaiton 3>` is useless. If we use `<location 2>`, it will be ignored. If `<location 1>` is a **NULL**, all entry and keys will be deleted. If there exist a string, only content will be deleted, not the entry.

### Example:

| Instuction                        | Arguments                        |
| --------------------------------  | --------------------------------------------------   |
| Add data of specific content     | ``-m ScheduleSQL.json -t "~/my/database/folder" -lc "\students\name\" -ac "Andrei"`` |
| Add entry of specific content    | ``-m ScheduleSQL.json -t "~/my/database/folder" -lc "\students\name\" -ac <NULL or "">`` |
| Modify data of specific content  | ``-m ScheduleSQL.json -t "~/my/database/folder" -lc "\students\name\" -mc "Alexandru"`` |
| Modify data of specific content with `<location 2>` argument  | ``-m ScheduleSQL.json -t "~/my/database/folder" -lc "\students\name\" -mc "Alexandru" "\age" "21"`` |
| Delete data and entries of specific content     | ``-m ScheduleSQL.json -t "~/my/database/folder" -lc "\students\" -dc NULL`` |
| Delete data and entries of specific content with `<location 2>` argument     | ``-m ScheduleSQL.json -t "~/my/database/folder" -lc "\students\name\" -dc "Alexandru" "\country" "Europe\Bucharest"`` |
| Delete entry of specific content  | ``-m ScheduleSQL.json -t "~/my/database/folder" -lc "\students\name\" -dc "Alexandru"`` |

* * Add data of specific content
     * Before:
```json
{
  "students": {
    "age"     : 17,
    "country" : "Europe/Bucharest"
  }
}
```

* * Add data of specific content
    * After:
```json
{
  "students": {
    "name"    : "Andrei",
    "age"     : 17,
    "country" : "Europe/Bucharest"
  }
}
```

* * Add entry of specific content
    * Before:
```json
{
  "students": {
    "age"     : 17,
    "country" : "Europe/Bucharest"
  }
}
```
* * Add entry of specific content
    * After:
```json
{
  "students": {
    "name"    : "",
    "age"     : 17,
    "country" : "Europe/Bucharest"
  }
}
```

* * Modify data of specific content
    * Before:
```json
{
  "students": {
    "name"    : "Andrei",
    "age"     : 17,
    "country" : "Europe/Bucharest"
  }
}
```
* * Modify data of specific content
    * Before:
```json
{
  "students": {
    "name"    : "Alexandru",
    "age"     : 17,
    "country" : "Europe/Bucharest"
  }
}
```

* * Modify data of specific content with `<location 2>` argument
    * Before:
```json
{
  "students": [
    {
      "name": "Alexandru",
      "age": 17,
      "country": "Europe/Bucharest"
    }
  ]
}
```
* * Modify data of specific content with `<location 2>` argument
    * After:
```json
{
  "students": [
    {
      "name": "Alexandru",
      "age": 21,
      "country": "Europe/Bucharest"
    }
  ]
}
```

* * Delete data and entries of specific content
    * Before:
```json
{
  "students": [
    {
      "name": "Alexandru",
      "age": 17,
      "country": "Europe/Bucharest"
    }
  ]
}
```
* * Delete data and entries of specific content
    * After:
```json
{
  "students": [
  ]
}
```

* * Delete data of specific content with `<location 2>` argument
    * Before:
```json
{
  "students": [
    {
      "name": "Alexandru",
      "age": 17,
      "country": "Europe/Bucharest"
    },
    {
      "name": "Alexandru",
      "age": 29,
      "country": "Europe/Slatina"
    },
    {
      "name": "Robert",
      "age": 19,
      "country": "Europe/Bucharest"
    }
  ]
}
```
* * Delete data of specific content with `<location 2>` argument
    * After:
```json
{
  "students": [
    {
      "name": "Alexandru",
      "age": 29,
      "country": "Europe/Slatina"
    },
    {
      "name": "Robert",
      "age": 19,
      "country": "Europe/Bucharest"
    }
  ]
}
```

* * Delete data of specific content
    * Before:
```json
{
  "students": [
    {
      "name": "Alexandru",
      "age": 17,
      "country": "Europe/Bucharest"
    },
    {
      "name": "Alexandru",
      "age": 29,
      "country": "Europe/Slatina"
    },
    {
      "name": "Robert",
      "age": 19,
      "country": "Europe/Bucharest"
    }
  ]
}
```
* * Delete data of specific content
    * After:
```json
{
  "students": [
    {
      "name": "Robert",
      "age": 19,
      "country": "Europe/Bucharest"
    }
  ]
}
```