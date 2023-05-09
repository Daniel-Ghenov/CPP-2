#pragma once

class State;

struct Link{

    char _letter = '\0';
    State* _ptr = nullptr;

    Link() = default;
    Link(char letter, State* ptr);

    bool operator==(const Link& other) const;
};