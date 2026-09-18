SELECT customer_number
FROM Orders
GROUP BY customer_number
HAVING COUNT(*) = (
    SELECT MAX(total_orders)
    FROM (
        SELECT COUNT(*) AS total_orders
        FROM Orders
        GROUP BY customer_number
    ) t
);