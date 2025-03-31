# LAB07 - Class Relationships and Reuse

The gist of this lab is a realization of the topics discussed in C++ Interlude 5 Class Relationships and Reuse.

## Background

Before proceeding with this lab, the student should take the time to read

* [C1.4.2 Redefining Base Class Functions](https://msu.vitalsource.com/reader/books/9780138122782/epubcfi/6/54%5B%3Bvnd.vst.idref%3DP7001018341000000000000000000B43%5D!/4/2%5BP7001018341000000000000000000B43%5D/36%5BP7001018341000000000000000000BD7%5D/2/2%5BP7001018341000000000000000000BD8%5D/5:20%5Blas%2Cs%20F%5D)
* [C++ Interlude 5 Class Relationships and Reuse](https://msu.vitalsource.com/reader/books/9780138122782/epubcfi/6/318%5B%3Bvnd.vst.idref%3DP7001018341000000000000000003D7E%5D!/4/2%5BP7001018341000000000000000003D7E%5D/2/2%5BP7001018341000000000000000003D7F%5D/7:0%5B%2CCla%5D)

## Objective

Upon successful completion of this lab, the student has learned (or reviewed) how to implement a(n)

* Is-A relationship via public inheritance
* As-A relationship via private inheritance

## Getting Started

After accepting this assignment with the
provided GitHub Classroom Assignment link, decide how you want to work with
your newly created repository:

- Using Codespaces directly in your web browser that employees the Visual Studio Code online IDE, or
- Using the IDE of your choice on your local machine

### Codespaces

If a Codespace is available for use (and this is your preferred method of development), open your newly created
repository in a Codespace.

At this point, you can skip to [Creating a development branch](#creating-a-development-branch).

### Local Development

Depending upon the IDE of your choice, many of the following steps may be taken within your IDE. It is up to you to
discover these tools (assuming they're available) and learn how to use them appropriately as desired. The following
instructions are assumed to take place within a terminal window. Note: many IDEs provide a terminal window as well.

#### Cloning your repository

The command you use to clone is slightly different depending upon whether
you're using `git` via `https`, `ssh`, or using the GitHub Cli via `gh`.

If you're using the `https` protocol, your clone command is:

```shell
git clone https://github.com/msu-csc232-sp25/<repo-name>.git
```

If you're using the `ssh` protocol, your clone command is:

```shell
git clone git@github.com:msu-csc232-sp25/<repo-name>.git
```

Finally, if you're using the GitHub CLI (`gh`), your clone command is:

```shell
gh repo clone msu-csc232-sp25/<repo-name>
```

After cloning the repository, navigate into the newly cloned repository:

```shell
cd <repo-name>
```

#### Creating a development branch

Next, create a branch named `develop`. Please note: The name of this branch **must** be as specified and will be, to the
grading scripts, case-sensitive.

```shell
git checkout -b develop
```

Make sure you are on the `develop` branch before you get started. Make all your commits on the `develop` branch.

```bash
git status
```

_You may have to type the `q` character to get back to the command line prompt after viewing the status._

## Tasks

This assignment consists of the following tasks:

- Task 1: Is-A relationship via public inheritance
- Task 2: As-A relationship via private inheritance

### Task 1: Is-A relationship via public inheritance

In this first task, you are to implement the IS_A relationship between two classes using public inheritance. See C++ Interlude 1 for a complete description of the `MagicBox` class.

NOTE: Before you begin, make sure you have created a `develop` branch within which to do your lab work!

1. Begin this task by locating the `TEST_TASK1` macro definition in the `csc232.h` header file and toggle its value from `FALSE` to `TRUE`.
2. Locate the `TODO: Task 1a` in the `magic_box.h` header file and declare the `MagicBox` class that IS_A a `PlainBox`.
3. Locate the `TODO: Task 1b` in the `magic_box.cpp` source file and define the appropriate `MagicBox` methods.
4. To check your solution, execute the `task1_test` target.
5. When you are satisified with the results of the unit tests, stage, commit and push your changes to GitHub.

### Task 2: As-A relationship via private inheritance

In your second, and final task, you are to implement an AS_A relationship. In this task, you'll be creating a class named `Safe` (in the `csc232` namespace) that uses private inheritance to reuse the methods of a `PlainBox` where needed in a `Safe`.

The `Safe` class has the following (private) attribute:

- `pass_code_` which must be of type `std::string`.

The `Safe` class has the following (public) methods:

- An initializing constructor that is used to intialize the `pass_code` which defaults to `"0000"` if no arguments are given upon construction.
- A mutator method named `open_and_store` that has two parameters declared in the following order:
    - `pass_code` whose value is checked against the internally stored `pass_code_`. If the codes don't match, this method returns `false`. If the codes match, the method stores the given item (second parameter) using the inherited `PlainBox<T>::set_item()` method and returns `true`
    - `item` the value to be stored in the safe
- A mutator method named `change_pass_code` that has two parameters declard in the following order:
    - `old_pass_code` (of type `std::string`) whose value is checked against the internally stored `pass_code_`. If the codes don't match, this method returns `false`. If the codes match, the internally stored `pass_code_` is updated with the value of the second parameter and `true` is returned.
    - `new_pass_code` (of type `std::string`) the new pass code to store internally assuming the first parameter matches the existing code
- An accessor method named `remove_item` that has one parameter
    - `pass_code` (of type `std::string`). If the given code matches the internally stored code, the item stored in the `Safe` is returned by calling the inherited `PlainBox<T>::get_item()` method. If the given code does not match the internally stored pass code, then a `logic_error` exception is thrown with an appropriate message. The content of the message should be meaningful, but it's actual content is up to you. The only requirement here is that if appropriate, you throw a `logic_error`.

1. Begin this task by locating the `TEST_TASK2` macro definition in the `csc232.h` header file and toggle its value from `FALSE` to `TRUE`.
2. Locate the `TODO: Task 2a` in the `safe.h` header file and declare the `Safe` class AS_A `PlainBox`.
3. Locate the `TODO: Task 2b` in the `safe.cpp` source file and define the appropriate `Safe` methods.
4. To check your solution, execute the `task2_test` target.
5. When you are satisified with the results of the unit tests, stage, commit and push your changes to GitHub.


## Submission Details

Before submitting your assignment, be sure you have pushed all your changes to GitHub. If this is the first time you're
pushing your changes, the push command will look like:

```bash
git push -u origin develop
```

If you've already set up remote tracking (using the `-u origin develop` switch), then all you need to do is type

```bash
git push
```

As usual, prior to submitting your assignment on Brightspace, be sure that you have committed and pushed your final
changes to GitHub. Once your final changes have been pushed, create a pull request that seeks to merge the changes in
your `develop` branch into your `trunk` branch.

You can use `gh` to create this pull request right from your command-line prompt:

```bash
gh pr create --assignee "@me" --title "Some appropriate title" --body "A message to populate description, e.g., Go Bills!" --head develop --base trunk --reviewer msu-csc232-sp25/graders
```

An "appropriate" title is at a minimum, the name of the assignment, e.g., `LAB02` or `HW04`, etc.

Once your pull request has been created, submit the URL of your assignment _repository_ (i.e., _not_ the URL of the pull
request) as a Text Submission on Brightspace. Please note: the timestamp of the submission on Brightspace is used to
assess any late penalties if and when warranted, _not_ the date/time you create your pull request. **No exceptions will
be granted for this oversight**.

### Due Date

Your assignment submission is due by the end of your lab period.

### Grading Rubric

This assignment is worth **3 points**.

| Criteria           | Exceeds Expectations         | Meets Expectations                  | Below Expectations                  | Failure                                        |
|--------------------|------------------------------|-------------------------------------|-------------------------------------|------------------------------------------------|
| Pull Request (20%) | Submitted early, correct url | Submitted on-time; correct url      | Incorrect URL                       | No pull request was created or submitted       |
| Code Style (20%)   | Exemplary code style         | Consistent, modern coding style     | Inconsistent coding style           | No style whatsoever or no code changes present |
| Correctness^ (60%) | All unit tests pass          | At least 80% of the unit tests pass | At least 60% of the unit tests pass | Less than 50% of the unit tests pass           |

^ _The Google Test unit runner will calculate the correctness points based purely on the fraction of tests passed_.

### Late Penalty

* In the first 24-hour period following the due date, this assignment will be penalized 20%.
* In the second 24-hour period following the due date, this assignment will be penalized 40%.
* After 48 hours, the assignment will not be graded and thus earns no points.

## Disclaimer & Fair Use Statement

This repository may contain copyrighted material, the use of which may not
have been specifically authorized by the copyright owner. This material is
available in an effort to explain issues relevant to the course or to
illustrate the use and benefits of an educational tool. The material
contained in this repository is distributed without profit for research and
educational purposes. Only small portions of the original work are being
used and those could not be used to easily duplicate the original work.
