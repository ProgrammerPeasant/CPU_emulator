#ifndef HEADER_GUARD_COMMAND_H_INCLUDED
#define HEADER_GUARD_COMMAND_H_INCLUDED

#include "arch.h"

//------------------
// Command subtypes
//------------------

enum CommandType : Cmd_t
{
    NOTHING = 0,
    BEGIN   = 1,
    END     = 2,
    PUSH    = 3,
    POP     = 4,
    PUSHR   = 5,
    POPR    = 6
};

class CommandBegin
{
public:
    CommandBegin() = default;

    static void execute() ;
};

class CommandEnd
{
public:
    CommandEnd() = default;

    static void execute() ;
};

class CommandPush
{
public:
    explicit CommandPush(Val_t val);

    void execute() const;
private:
    Val_t val_;
};

class CommandPop
{
public:
    CommandPop() = default;

    static void execute() ;
};

class CommandPushr
{
public:
    explicit CommandPushr(Reg_t reg);

    void execute() const;
private:
    Reg_t reg_;
};

class CommandPopr
{
public:
    explicit CommandPopr(Reg_t reg);

    void execute() const;
private:
    Reg_t reg_;
};

class Command
{
public:
    // Existance management:
    Command();
    explicit Command(CommandBegin* cmd);
    explicit Command(CommandEnd*   cmd);
    explicit Command(CommandPush*  cmd);
    explicit Command(CommandPop*   cmd);
    explicit Command(CommandPushr* cmd);
    explicit Command(CommandPopr*  cmd);

    ~Command();

    // Ensure command is never copied:
    Command(const Command&) = delete;
    Command(Command&&) noexcept ;

    Command& operator=(const Command&) = delete;
    Command& operator=(Command&&) noexcept ;

    // Command execution:
    void execute() const;

private:
    // Memory management utility:
    void release();

    CommandType type_;

    void* ptr_;
};

#endif