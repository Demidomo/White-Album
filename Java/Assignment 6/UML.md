              +-----------------------+
              |         Order         |
              +-----------------------+
              | + orderID: int        |
              | + orderDate: Date     |
              | + status: String      |
              | + amount: double      |
              | + customer: Customer  |
              | - orderItems: List<OrderItem> |
              | - payments: List<Payment>    |
              | - details: List<Details>     |
              +-----------------------+
                        |1
                        |
                        |*
              +-----------------------+
              |      OrderDetails     |
              +-----------------------+
              | + quantity: int       |
              | + price: double       |
              | - orderItem: OrderItem|
              | - product: Product    |
              +-----------------------+
                        |1
                        |
                        |*
              +-----------------------+
              |       OrderItem       |
              +-----------------------+
              | + orderItemID: int    |
              | + orderDetails: OrderDetails |
              +-----------------------+
                        |
                        |
              +-----------------------+
              |       Customer        |
              +-----------------------+
              | + customerID: int     |
              | + firstName: String   |
              | + lastName: String    |
              | + address: String     |
              | + phone: String       |
              +-----------------------+
                        |
                        |
              +-----------------------+
              |        Payment        |
              +-----------------------+
              | + paymentID: int      |
              | + paymentDate: Date   |
              | + amount: double      |
              | + order: Order        |
              | - paymentType: PaymentType |
              +-----------------------+
                        |
                        |
            +-------------+------------+
            |                          |
            |                          |
  +----------------+        +------------------+
  |      Cash      |        |      Cheque      |
  +----------------+        +------------------+
  |                |        | + chequeNumber: String |
  +----------------+        +------------------+
                                   |
                                   |
                             +----------------+
                             |     Credit     |
                             +----------------+
                             | + cardNumber: String |
                             | + expiryDate: Date   |
                             | + cvv: String        |
                             +----------------+
                        |
                        |
              +-----------------------+
              |        Details        |
              +-----------------------+
              | + detailsID: int      |
              | + description: String |
              | + quantity: int       |
              | + price: double       |
              +-----------------------+
