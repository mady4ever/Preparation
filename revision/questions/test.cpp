#include<bits/stdc++.h>
int GetWaysOfParenthesizeExpressionRecursion(string expression, bool result)
        {
            if (expression.Count() == 1)
            {
                return (expression.Equals("1") && result) || (expression.Equals("0") && !result) ? 1 : 0;
            }

            var count = 0;
            for (var i = 1; i < expression.Count() - 1; i = i + 2)
            {
                var left = expression.Substring(0, i);
                var right = expression.Substring(i + 1);
                switch (expression[i])
                {
                    case '|':
                        {
                            if (result)
                            {
                                count += this.GetWaysOfParenthesizeExpressionRecursion(left, true)
                                         * this.GetWaysOfParenthesizeExpressionRecursion(right, true);
                                count += this.GetWaysOfParenthesizeExpressionRecursion(left, true)
                                         * this.GetWaysOfParenthesizeExpressionRecursion(right, false);
                                count += this.GetWaysOfParenthesizeExpressionRecursion(left, false)
                                         * this.GetWaysOfParenthesizeExpressionRecursion(right, true);
                            }
                            else
                            {
                                count += this.GetWaysOfParenthesizeExpressionRecursion(left, false)
                                         * this.GetWaysOfParenthesizeExpressionRecursion(right, false);
                            }
                        }
                        break;
                    case '&':
                        {
                            if (result)
                            {
                                count += this.GetWaysOfParenthesizeExpressionRecursion(left, true)
                                         * this.GetWaysOfParenthesizeExpressionRecursion(right, true);
                            }
                            else
                            {
                                count += this.GetWaysOfParenthesizeExpressionRecursion(left, true)
                                         * this.GetWaysOfParenthesizeExpressionRecursion(right, false);
                                count += this.GetWaysOfParenthesizeExpressionRecursion(left, false)
                                         * this.GetWaysOfParenthesizeExpressionRecursion(right, true);
                                count += this.GetWaysOfParenthesizeExpressionRecursion(left, false)
                                         * this.GetWaysOfParenthesizeExpressionRecursion(right, false);
                            }
                        }
                        break;
                    case '^':
                        {
                            if (result)
                            {
                                count += this.GetWaysOfParenthesizeExpressionRecursion(left, true)
                                         * this.GetWaysOfParenthesizeExpressionRecursion(right, false);
                                count += this.GetWaysOfParenthesizeExpressionRecursion(left, false)
                                         * this.GetWaysOfParenthesizeExpressionRecursion(right, true);
                            }
                            else
                            {
                                count += this.GetWaysOfParenthesizeExpressionRecursion(left, true)
                                         * this.GetWaysOfParenthesizeExpressionRecursion(right, true);
                                count += this.GetWaysOfParenthesizeExpressionRecursion(left, false)
                                         * this.GetWaysOfParenthesizeExpressionRecursion(right, false);
                            }
                        }
                        break;
                }
            }

            return count;
        }
