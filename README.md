ScheduleSQL

* License [![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](LICENSE)

* Build Status [![Build Status](https://travis-ci.com/nicugnm/ScheduleSQL.svg?branch=main)](https://travis-ci.org/nicugnm/ScheduleSQL)

* Tests ![Tests]()




Introduction
-------------

ScheduleSQL is a C program and reproduces SQL commands using arguments.

Something about it:

* Written in C, ScheduleSQL is faster and stable.
* Having a friendly structure, it's easy to contribute to it.
* You need to have installed library: `jq`
*
    * For that, use `apt install jq`

# Script flags

| Script flags | Description                                                                           |
| ------------ | ------------------------------------------------------------------------------------- |
| -c           | Will create database file                               |
| -d           | Delete data                                                                      |
| -m           | Modify data                                                                 |
| -t           | Set target                           | |
| -mc          | Add/Modify content
| -dc          | Delete content
| -lc          | Location of content

### Example:

| Instruction                        | Arguments                        |
| --------------------------------  | --------------------------------------------------   |
| Create database                   | ``-c ScheduleSQL.json -t "~/my/database/folder"``  |
| Delete database                   | ``-d ScheduleSQL.json -t "~/my/database/folder"``  |
| Add data of specific database  | ``-m ScheduleSQL.json -t "~/my/database/folder" -lc student -mc "Andrei"`` |
| Modify data of specific database | ``-m ScheduleSQL.json -t "~/my/database/folder" -lc student -mc "Andrei Stefan"`` |
| Delete data of specific database | ``-m ScheduleSQL.json -t "~/my/database/folder" -lc student -dc"`` |

## Syntax Arguments

``-<type of action> <name of database> -<instruction flag> <location database> -<interaction flag> <location 1> -<instruction type flag> <location 2>``

| Type of action | Instruction flag | Interaction flag | Instruction Type flag |
| :---: | :---: | :---: | :---: |
| -c | -t | -lc | -mc
| -d |    |  | -dc
| -m |    |  |

**Type of action** flag is mandatory. This flag is used to know what we want to do:

* If we want to create a database, we will use `-c` argument.
* If we want to delete a database, we will use `-d` argument.
* If we want to modify a database, we will use `-m` argument.

**Instruction** flag is optional. This flag is used, for now, only to get target/folder location of database.

**Interaction** flag is optional. With this flag we set action of interaction

* It can be `add/modify/delete` content using: `-mc / -dc`

**Instruction Type flag** is mandatory if there exist **Interaction** flag.

* About them:
    - If we use `-mc`, key `<location 2>` is mandatory and has to be always a string. We use `-mc` when we want to
      modify content or add content of actual structure, using entry of `<location 1>`. If it exist, we will
      modify `-lc` with entry from `<location 1>`, using data of `<location 2>`.
    - If we use `-dc`, key `<location 2>` is useless. If we use `<location 2>`, it will be ignored.

### Example:

| Instuction                        | Arguments                        |
| --------------------------------  | --------------------------------------------------   |
| Add data of specific content     | ``-m ScheduleSQL.json -t ~/my/database/folder -lc key_name -ac "Andrei"`` |
| Add entry of specific content    | ``-m ScheduleSQL.json -t ~/my/database/folder -lc key_name -ac <"">`` |
| Modify data of specific content  | ``-m ScheduleSQL.json -t ~/my/database/folder -lc key_name -mc "Alexandru"`` |

* * Add data of specific content
     * Before:

```json
{
  "age"     : 17,
  "country" : "Europe/Bucharest"
}
```

* * Add data of specific content
    * After:

```json
{
  "name"    : "Andrei",
  "age"     : 17,
  "country" : "Europe/Bucharest"
}
```

* * Add entry of specific content
    * Before:

```json
{
  "age"     : 17,
  "country" : "Europe/Bucharest"
}
```
* * Add entry of specific content
    * After:

```json
{
  "name"    : "",
  "age"     : 17,
  "country" : "Europe/Bucharest"
}
```

* * Modify data of specific content
    * Before:

```json
{
  "name"    : "Andrei",
  "age"     : 17,
  "country" : "Europe/Bucharest"
}
```

*
    * Modify data of specific content
        * After:

```json
{
  "name"    : "Alexandru",
  "age"     : 17,
  "country" : "Europe/Bucharest"
}
```

# TODO : ARRAYS

*
    * Modify data of specific content with `<location 2>` argument
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