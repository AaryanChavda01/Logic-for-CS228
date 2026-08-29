# Logic for CS228
## Description:

Modeling formal logic in C++, closely following CS228 (Logic for computer science) course at IITB.

Lecture content will be used for definitions, conventions and algorithms.

## Lecture 1
### Contents:

1. Defining atomic propositions
2. Introducing logical connectives
3. Defining propositional formulae
4. The program
5. How to run

---

### 1. Defining atomic propositions:

A finite `string` of letters/symbols without inherent meaning along with a boolean value (`true` or `false`).

The set of all atomic propositions will be denoted by **AP**.

---

### 2. Introducing logical connectives
Following are the logical connectives defined:

| Formal Name | Symbol | Read as|
| :---: | :---: | :---: |
| true | $\top$ | top |
| false | $\bot$ | bot |
| negation | $\lnot$ | not |
| conjunction | $\land$ | and |
| disjunction | $\lor$ | or |
| implication | $\to$ | implies |
| equivalence | $\leftrightarrow$ | iff |
| exclusive or | $\oplus$ | xor |
| open parenthesis | ( | |
| close parenthesis | ) | |

Though, a different set of symbols will be used to denote the logical connectives using strings with ASCII characters in this program:

| Formal Name | String Representation | Read as|
| :---: | :---: | :---: |
| negation | `~` | not |
| conjunction | `*` | and |
| disjunction | `+` | or |
| implication | `->` | implies |
| equivalence | `<->` | iff |
| exclusive or | `^` | xor |
| open parenthesis | `(` | |
| close parenthesis | `)` | |

Note: $\top$ (or $\bot$) are not included in logical connectives as they are just atomic propositions with `name` and `value` as `true` (or `false`).

---

### 3. Defining propositional formulae

A propositional formula is a finite `string` containing atomic propositions and logical connectives and satisfies the following rule:

$F \in$ **Prop** if

$F ::= p|\top|\bot|\lnot F|(F\lor F)|(F\land F)|(F\to F)|(F\leftrightarrow F)|(F\oplus F)$

where $p \in$ **AP**.

Any formula that satisfies this rule is *well-formed*.

**Prop** is the set of all propositional formulae.

---

### 4. The program
The program determines if given string is a propositional formula and stores the atomic propositions it contains and prints the result.

Input:
* `n`: 1 integer representing number of testcases
* `n` `string`s representing some propositional formula

Output:
* `string` *formula* representing the string itself
* `bool` *well-formed* representing if it is well-formed
* `variables` representing propositions the formula contains

---

### 5. How to run
Run `make` to produce and run the main executable

Run `make clean` to remove all generated files

---

## Lecture 2
### Contents:

1. Parse Trees
2. Assignments and Valuations
3. Truth Tables
4. Satisfiability and Validity
5. The program
6. How to run

---

### 1. Parse Trees

**Definition**: A **parse tree** of a *formula* F $\in$ **Prop** is a tree such that:
* The root is F,
* leaves are atomic propositions, and
* each internal node is formed by applying some logical connective to its children.

---

### 2. Assignments and Valuations

**Definition**: An ***assignment*** is a map from **AP** $\to$ {0,1}.

**Definition**: A ***Valuation*** or a *model* *m* of a propositional formula *F* $\in$ **Prop** is an assignment of each atomic proposition in *F* to a truth value

**Definition**: The ***semantics*** of *F* $\in$ **Prop**, denoted [|F|], is a map from {0,1}$^{AP}$ $\to$ {0,1}.

---

### 3. Truth Tables

Representation of the semantics of a formula in tabular form.

---

### 4. Satisfiability and Validity

**Definition**: F $\in$ **Prop** is said to be **satisfiable** if there exists a valuation *m* of F such that *m*(F) = 1, i.e., [|F|] = 1.

**Definition**: F $\in$ **Prop** is said to be **valid** if for all valuations *m* of F, *m*(F) = 1, i.e., [|F|] = 1.

Valid formulas are called **tautologies**.

Note: $F \in$ **Prop** is satisfiable iff $\lnot F$ is not valid.

---

### 5. The program

The program calculates and prints the truth table for any well formed propositional formula given and outputs whether it is satisfiable and valid.

Input:
* `n`: 1 integer representing number of testcases
* `n` `string`s representing some propositional formula

Output:
* The Truth Table of F.
* "Satisfiable: " with "YES" or "NO" determining whether given formula is satisfiable.
* "Valid: " with "YES" or "NO" determining whether given formula is valid.

---

### 6. How to run

Run `make` to produce and run the main executable

Run `make clean` to remove all generated files

---