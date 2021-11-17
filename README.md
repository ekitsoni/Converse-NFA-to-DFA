# Converse-NFA-to-DFA

The basic idea of the code is to construct the deterministic finite automaton from a non-deterministic finite automaton as a human would construct it. Following its short creation, it takes only the situations that are accessible from the original instead of creating all the possible combinations of situations. We assume the input file is correct. The first 4 lines give us the information we need and the rest are the transitions, each symbol is separated from the next by a space and there are no empty lines. The programming language is used is C++.
