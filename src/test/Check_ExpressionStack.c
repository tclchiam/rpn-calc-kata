#include <check.h>
#include <ExpressionStack.h>

#include "CheckSuites.h"

START_TEST(test_expression_stack_create)
    {
        ExpressionStack *stack = new_expression_stack(0);

        ck_assert_ptr_ne(NULL, stack);

        free_expression_stack(stack);
    }
END_TEST

START_TEST(test_expression_stack_pop_returns_in_reverse_push_order)
    {
        ExpressionStack *stack = new_expression_stack(3);

        push(stack, 'a');
        push(stack, 'b');
        push(stack, 'c');

        ck_assert_int_eq('c', pop(stack));
        ck_assert_int_eq('b', pop(stack));
        ck_assert_int_eq('a', pop(stack));

        free_expression_stack(stack);
    }
END_TEST

START_TEST(test_expression_stack_is_empty_returns_true_for_empty_stack)
    {
        ExpressionStack *stack = new_expression_stack(0);

        ck_assert_int_eq(true, is_empty(stack));

        free_expression_stack(stack);
    }
END_TEST

START_TEST(test_expression_stack_is_empty_returns_false_for_non_empty_stack)
    {
        ExpressionStack *stack = new_expression_stack(1);

        push(stack, 'a');

        ck_assert_int_eq(false, is_empty(stack));

        free_expression_stack(stack);
    }
END_TEST

START_TEST(test_expression_stack_peak_returns_value_of_top)
    {
        ExpressionStack *stack = new_expression_stack(2);

        push(stack, 'a');
        push(stack, 'b');

        ck_assert_int_eq('b', peak(stack));

        free_expression_stack(stack);
    }
END_TEST


Suite *expression_stack() {
    Suite *suite;
    TCase *tcase_core;

    suite = suite_create("RPN Calculator - Expression Stack");

    tcase_core = tcase_create("Core");

    tcase_add_test(tcase_core, test_expression_stack_create);
    tcase_add_test(tcase_core, test_expression_stack_pop_returns_in_reverse_push_order);
    tcase_add_test(tcase_core, test_expression_stack_is_empty_returns_true_for_empty_stack);
    tcase_add_test(tcase_core, test_expression_stack_is_empty_returns_false_for_non_empty_stack);
    tcase_add_test(tcase_core, test_expression_stack_peak_returns_value_of_top);

    suite_add_tcase(suite, tcase_core);

    return suite;
}