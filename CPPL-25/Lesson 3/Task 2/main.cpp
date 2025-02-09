//подключаем макросы catch2
#include <catch2/catch_test_macros.hpp>

#include <cstdint>

#include <iostream>

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    //проверяемая функция #1
    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    //проверяемая функция #2
    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    //проверяемая функция #3
    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    //проверяемая функция #4
    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};


//юнит-тест #1 
TEST_CASE("Number after adding to the beginning", "[PushFront]")
{
    List list;

    list.PushFront(1);
    REQUIRE(list.PopFront() == 1);
    list.PushFront(55);
    REQUIRE(list.PopFront() == 55);
    list.PushBack(10);
    REQUIRE(list.PopFront() == 55);
}

//юнит-тест #2
TEST_CASE("Number after adding to the end", "[PushBack]")
{
    List list;

    list.PushBack(123);
    REQUIRE(list.PopBack() == 123);
    list.PushFront(10);
    REQUIRE(list.PopBack() == 123);
    list.PushBack(5);
    REQUIRE(list.PopBack() == 5);

}

//юнит-тест #3
TEST_CASE("Checking if a function PopFront() works correctly on an empty list", "[PopFront]")
{
    List list;

    REQUIRE_THROWS(list.PopFront(), "list is empty");
}

//юнит-тест #4
TEST_CASE("Checking if a function PopBack() works correctly on an empty list", "[PopBack]")
{
    List list;

    REQUIRE_THROWS(list.PopBack() == true);
}

//юнит-тест #5
TEST_CASE("Checking all four functions", "[PushFront, PushFront, PopFront, PopBack]")
{
    List list;

    list.PushFront(1);
    REQUIRE(list.PopFront() == 1);
    list.PushFront(55);
    list.PushBack(5);
    REQUIRE(list.PopFront() == 55);
    REQUIRE(list.PopBack() == 5);
    list.PushBack(10);
    REQUIRE(list.PopFront() == 10);

    list.PushFront(1);
    list.Clear();
    REQUIRE_THROWS(list.PopFront(), "list is empty");



    list.PushBack(123);
    REQUIRE(list.PopBack() == 123);
    list.PushFront(10);
    REQUIRE(list.PopBack() == 55);
    list.PushBack(5);
    REQUIRE(list.PopBack() == 5);


    list.PushFront(1);
    REQUIRE_THROWS(list.PopBack(), "list is empty");

    list.Clear();
}
