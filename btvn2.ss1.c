#include <stdio.h>

int main() {
    int food_id;
    float unit_price;
    int quantity;
    float distance;
    int is_peak;
    int is_store_open;
    int stock;
    char account_type;
    float subtotal;
    float base_shipping_fee;
    int freeship;
    float freeship_discount;
    float peak_surcharge;
    int order_valid;
    float final_amount;

    printf("==================================================\n");
    printf("          SHOPEEFOOD ORDER CHECKOUT SYSTEM\n");
    printf("==================================================\n");

    printf("Nhap ma mon an: ");
    scanf("%d", &food_id);

    printf("Nhap don gia mon an (VND): ");
    scanf("%f", &unit_price);

    printf("Nhap so luong dat: ");
    scanf("%d", &quantity);

    printf("Nhap khoang cach giao hang (km): ");
    scanf("%f", &distance);

    printf("Nhap trang thai gio cao diem (1/0): ");
    scanf("%d", &is_peak);

    printf("Nhap trang thai cua hang (1/0): ");
    scanf("%d", &is_store_open);

    printf("Nhap so luong ton kho: ");
    scanf("%d", &stock);

    printf("Nhap loai tai khoan (V/N): ");
    scanf(" %c", &account_type);

    subtotal = unit_price * quantity;

    base_shipping_fee = distance * 5000.0;

    freeship = ((subtotal >= 100000.0) && (distance <= 5.0))|| (account_type == 'V');

    freeship_discount = 15000.0 * freeship * (base_shipping_fee >= 15000.0) + base_shipping_fee * freeship * (base_shipping_fee < 15000.0);

    peak_surcharge = 10000.0 * is_peak;

    order_valid =(is_store_open == 1)&& (stock >= quantity)&& (quantity > 0)&& (unit_price > 0);

    final_amount =(subtotal + base_shipping_fee - freeship_discount + peak_surcharge) * order_valid;

    printf("\n");
    printf("==================================================\n");
    printf("          SHOPEEFOOD ORDER CHECKOUT SYSTEM\n");
    printf("==================================================\n");

    printf("Ma mon an             : %d\n", food_id);
    printf("Don gia                : %.2f VND\n", unit_price);
    printf("So luong dat           : %d\n", quantity);
    printf("Khoang cach giao       : %.2f km\n", distance);
    printf("Khung gio cao diem    : %d\n", is_peak);
    printf("Trang thai cua hang   : %d\n", is_store_open);
    printf("So luong ton kho      : %d\n", stock);
    printf("Loai tai khoan         : %c ", account_type);
    printf("--------------------------------------------------\n");
    printf("TONG TIEN MON AN      : %.2f VND\n", subtotal);
    printf("PHI GIAO HANG CO BAN  : %.2f VND\n", base_shipping_fee);
    printf("GIAM GIA FREESHIP      : %.2f VND\n", freeship_discount);
    printf("PHU PHI GIO CAO DIEM  : %.2f VND\n", peak_surcharge);

    printf("--------------------------------------------------\n");

    printf("DON HANG HOP LE       : %d (1: HOP LE / 0: TU CHOI)\n",order_valid);

    printf("TONG THANH TIEN       : %.2f VND\n", final_amount);

    printf("==================================================\n");

    return 0;
}
