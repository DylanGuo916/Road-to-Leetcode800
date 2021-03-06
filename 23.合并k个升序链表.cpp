/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    return merge(lists, 0, lists.size() - 1);
  }
private:
  ListNode* merge(vector<ListNode*>& lists, int l, int r) {
    if (l > r) return nullptr;
    if (l == r) return lists[l];
    if (l + 1 == r) return mergeTwoLists(lists[l], lists[r]);
    int mid = l + (r - l) / 2;
    auto l1 = merge(lists, l, mid);
    auto l2 = merge(lists, mid + 1, r);
    return mergeTwoLists(l1, l2);
  }

  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    while (l1 && l2) {
      if (l1->val <= l2->val) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
  }
};
// @lc code=end

