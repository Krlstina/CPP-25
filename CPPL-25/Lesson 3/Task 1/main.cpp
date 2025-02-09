//подключаем макросы catch2
#include <catch2/catch_test_macros.hpp>

#include <cstdint>


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
    //проверяемая функция #1
    bool Empty() { return m_size == 0; }    

    //проверяемая функция #2
    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    //проверяемая функция #3
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
TEST_CASE("List is empty after create?", "[Empty]")
{
    List list;

    REQUIRE(list.Empty() == 0);
}

//юнит-тест #2
TEST_CASE("Size after adding elements", "[Size]")
{
    List list;

    list.PushFront(1);
    REQUIRE(list.Size() == 1);
    list.PushBack(10);
    REQUIRE(list.Size() == 2);
    list.PushFront(5);
    REQUIRE(list.Size() == 3);
}

//юнит-тест #3
TEST_CASE("List is empty after Clean()", "[Clear]")
{
    List list;

    list.PushFront(1);
    list.Clear();
    REQUIRE(list.Empty() == 0);
}