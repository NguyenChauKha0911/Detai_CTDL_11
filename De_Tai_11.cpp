#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//=================================================================================================
typedef struct monHoc {
    char maMonHoc[16];
    char tenMonHoc[46];
    char loaiMonHoc[16];
    int soTC;
    char heDaoTao[16];
}ItemType;
//=================================================================================================
typedef struct BSTNode {
    ItemType Info;
    BSTNode* Left;
    BSTNode* Right;
}BSTNode;
//=================================================================================================
typedef struct BSTree {
    BSTNode* Root;
}BSTree;
//=================================================================================================
typedef struct SNode {
    ItemType Info;
    SNode* Next;
}SNode;
//=================================================================================================
typedef struct SList {
    SNode* Head;
    SNode* Tail;
}SList;
//=================================================================================================
typedef struct loaiMH {
    char loai[16];
    int SL;
}loaiMH;
//=================================================================================================
void process();
void menu();
BSTNode* createBSTNode(ItemType x);
void showBSTNode(BSTNode* p);
void deleteBSTNode(BSTNode*& p);
void initBSTree(BSTree& bt);
int insertBSTNode(BSTNode*& root, BSTNode* p);
// void createBSTree_FromArray(BSTree& bt);
// void createBSTree_Random(BSTree& bt);
void createBSTree_FromFile(BSTree& bt);
void createBSTree_byHand(BSTree& bt);
void traverseNLR(BSTNode* root);
void traverseLNR(BSTNode* root);
void traverseLRN(BSTNode* root);
void traverseNRL(BSTNode* root);
void traverseRNL(BSTNode* root);
void traverseRLN(BSTNode* root);
int countBSTNode(BSTNode* root);
// BSTNode* findBSTNode(BSTNode* root, ItemType x);
// void NutLonHonX(BSTNode* root, ItemType x);
int countBSTNodeIsLeaf(BSTNode* root);
int countBSTNodeHaveOneChild(BSTNode* root);
int countBSTNodeHaveTwoChild(BSTNode* root);
int highTree(BSTNode* root);
// int SumBSTNode(BSTNode* root);
// int SumBSTNodeIsLeaf(BSTNode* root);
// int SumBSTNodeHaveOneChild(BSTNode* root);
// int SumBSTNodeHaveTwoChild(BSTNode* root);
void initSlist(SList& sl);
int insertTail(SList& sl, SNode* p);
SNode* createSNode(ItemType x);
void thongkeTheoTC(BSTNode* root, SList& sl1, SList& sl2, SList& sl3);
void showSlist(SList sl, int x);
void demSLtheoLoaiMonHoc(BSTNode* root, loaiMH* a, int& soLoai);
int sumTC(BSTNode *root);
int deleteBSTNodeX(BSTNode *&root, char tenMH[]);
BSTNode *findBSTNodeReplace(BSTNode *&p);
BSTNode *findBSTNodeTheoTenMH(BSTNode *root, char x[]);
void nhapTTMotMonHoc(BSTree &bt);
//=================================================================================================
int main() {
    process();
    return 0;
}
//=================================================================================================
void process() {
    int choice, n;
    BSTree bt;
    SList sl1, sl2, sl3;
    do {
        menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                printf("\n***Co 2 cach nhap du lieu vao cay NPTK***");
                printf("\n1. Nhap du lieu vao cay NPTK tu file.");
                printf("\n2. Nhap du lieu vao cay NPTK tu ban phim.\n");
                do {
                    printf("Ban muon nhap du lieu vao cay NPTK theo cach nao(1->4): ");
                    scanf("%d", &n);
                }while(n < 1 || n > 2);
                if(n == 1)
                    createBSTree_FromFile(bt);
                else
                    createBSTree_byHand(bt);
                break;
            }
            case 2: {
                printf("\n***Co 6 cach duyet cay NPTK***");
                printf("\n1. Node Left Right.");
                printf("\n2. Left Node Right.");
                printf("\n3. Left Right Node.");
                printf("\n4. Node Right Left.");
                printf("\n5. Right Node Left.");
                printf("\n6. Right Left Node.\n");
                do {
                    printf("Ban muon duyet cay NPTK theo cach nao(1->6): ");
                    scanf("%d", &n);
                }while(n < 1 || n > 6);
                switch(n) {
                    case 1:
                        printf("\n========================================Duyet cay theo kieu NLR========================================");
                        printf("\n%-16s%-46s%-16s%-14s%-16s", "Ma mon hoc", "Ten mon hoc", "Loai mon hoc", "So tin chi", "He dao tao");
                        traverseNLR(bt.Root);
                        break;
                    case 2:
                        printf("\n========================================Duyet cay theo kieu LNR========================================");
                        printf("\n%-16s%-46s%-16s%-14s%-16s", "Ma mon hoc", "Ten mon hoc", "Loai mon hoc", "So tin chi", "He dao tao");
                        traverseLNR(bt.Root);
                        break;
                    case 3:
                        printf("\n========================================Duyet cay theo kieu LRN========================================");
                        printf("\n%-16s%-46s%-16s%-14s%-16s", "Ma mon hoc", "Ten mon hoc", "Loai mon hoc", "So tin chi", "He dao tao");
                        traverseLRN(bt.Root);
                        break;
                    case 4:
                        printf("\n========================================Duyet cay theo kieu NRL========================================");
                        printf("\n%-16s%-46s%-16s%-14s%-16s", "Ma mon hoc", "Ten mon hoc", "Loai mon hoc", "So tin chi", "He dao tao");
                        traverseNRL(bt.Root);
                        break;
                    case 5:
                        printf("\n========================================Duyet cay theo kieu RNL========================================");
                        printf("\n%-16s%-46s%-16s%-14s%-16s", "Ma mon hoc", "Ten mon hoc", "Loai mon hoc", "So tin chi", "He dao tao");
                        traverseRNL(bt.Root);
                        break;
                    case 6:
                        printf("\n========================================Duyet cay theo kieu RLN========================================");
                        printf("\n%-16s%-46s%-16s%-14s%-16s", "Ma mon hoc", "Ten mon hoc", "Loai mon hoc", "So tin chi", "He dao tao");
                        traverseRLN(bt.Root);
                        break;
                }
                break;
            }
            case 3: {
                ItemType x;
                printf("\nNhap gia tri nut muon them vao cay NPTK: ");
                scanf("%d", &x);
                BSTNode* p = createBSTNode(x);
                insertBSTNode(bt.Root, p);
                printf("Da them nut co gia tri %d vao cay NPTK.", x);
                break;
            }
            case 4: {
                printf("\n***Dem nut tren cay NPTK***");
                printf("\n1. Dem tat ca nut co tren NPTK.");
                printf("\n2. Dem nut la.");
                printf("\n3. Dem nut 1 con.");
                printf("\n4. Dem nut 2 con.");
                printf("\n5. Tinh chieu cao cay NPTK.\n");
                do {
                    printf("Ban dem theo cach nao(1->5): ");
                    scanf("%d", &n);
                }while(n < 1 || n > 5);
                switch(n) {
                    case 1: 
                        printf("\nSo nut co trong cay NPTK = %d", countBSTNode(bt.Root));
                        break;
                    case 2:
                        printf("\nSo nut la co trong cay NPTK = %d", countBSTNodeIsLeaf(bt.Root));
                        break;
                    case 3:
                        printf("\nSo nut co 1 con trong cay NPTK = %d", countBSTNodeHaveOneChild(bt.Root));
                        break;
                    case 4:
                        printf("\nSo nut co 2 con trong cay NPTK = %d", countBSTNodeHaveTwoChild(bt.Root));
                        break;
                    case 5:
                        printf("\nChieu cao cua cay NPTK = %d", highTree(bt.Root));
                        break;
                }
                break;
            }
            case 5: {
                char tenMH[46];
                getchar();
                printf("\nNhap ten mon hoc muon xoa khoi cay NPTK: ");
                fgets(tenMH, 46, stdin);
                tenMH[strcspn(tenMH, "\n")] = 0;
                BSTNode *p = findBSTNodeTheoTenMH(bt.Root, tenMH);
                if(p) {
                    deleteBSTNodeX(bt.Root, p->Info.maMonHoc);
                    printf("Da xoa mon hoc '%s' khoi cay NPTK.", tenMH);
                }
                else
                    printf("Khong ton tai mon hoc '%s' trong cay NPTK.", tenMH);
                break;
            }
            case 6: {
                nhapTTMotMonHoc(bt);
                break;
            }
            case 7: {
                char tenMH[46];
                getchar();
                printf("\nNhap ten mon hoc can tim: ");
                fgets(tenMH, 46, stdin);
                tenMH[strcspn(tenMH, "\n")] = 0;
                BSTNode* p = findBSTNodeTheoTenMH(bt.Root, tenMH);
                if(p) {
                    printf("\n%-16s%-46s%-16s%-14s%-16s", "Ma mon hoc", "Ten mon hoc", "Loai mon hoc", "So tin chi", "He dao tao");
                    showBSTNode(p);
                }
                else
                    printf("Khong ton tai mon hoc '%s' trong cay NPTK.", tenMH);
                break;
            }
            case 8: {
                initSlist(sl1);
                initSlist(sl2);
                initSlist(sl3);
                thongkeTheoTC(bt.Root, sl1, sl2, sl3);
                showSlist(sl1, 1);
                showSlist(sl2, 2);
                showSlist(sl3, 3);
                break;
            }
            case 9: {
                loaiMH* a = new loaiMH;
                int n = 0;
                // strcpy(a[0].loai, bt.Root->Info.loaiMonHoc);
                demSLtheoLoaiMonHoc(bt.Root, a, n);
                for(int i = 0; i<n ; i++) {
                    printf("\nLoai mon hoc '%s' co %d mon.", a[i].loai, a[i].SL);
                }
                // delete a;
                break;
            }
            case 10: {
                printf("\nTong so tin chi cua mon hoc = %d", sumTC(bt.Root));
                break;
            }
        }
    }while(choice != 0);
}
//=================================================================================================
void menu() {
    printf("\n**********************************************************************************");
    printf("\n*                                  MENU                                          *");
    printf("\n**********************************************************************************");
    printf("\n*0.Nhap 0 de thoat.                                                              *");
    printf("\n*1.Nhap du lieu vao cay NPTK.                                                    *");
    printf("\n*2.Duyet cay NPTK.                                                               *");
    printf("\n*3.Them mot nut co gia tri x vao cay NPTK.                                       *");
    printf("\n*4.Dem nut tren cay NPTK.                                                        *");
    printf("\n*5.Tim nut co gia tri x trong cay NPTK.                                          *");
    printf("\n*6.In ra cac nut co gia tri lon hon x trong cay NPTK.                            *");
    printf("\n*7.Tinh tong trong cay NPTK.                                                     *");
    printf("\n**********************************************************************************");
    printf("\n=> Moi nhap lua chon cua ban: ");
}
//=================================================================================================
BSTNode* createBSTNode(ItemType x) {
    BSTNode* p = new BSTNode;
    if(p == NULL) {
        printf("\nKhong du bo nho cap phat nut moi.");
        return NULL;
    }
    p->Info = x;
    p->Left = NULL;
    p->Right = NULL;
    return p;
}
//=================================================================================================
void showBSTNode(BSTNode* p) {
    if(p == NULL) return;
    printf("\n%-16s%-46s%-16s%-14d%-16s", p->Info.maMonHoc, p->Info.tenMonHoc, p->Info.loaiMonHoc, p->Info.soTC, p->Info.heDaoTao);
}
//=================================================================================================
void deleteBSTNode(BSTNode*& p) {
    if(p == NULL) return;
    p->Left = NULL;
    p->Right = NULL;
    delete p;
}
//=================================================================================================
void initBSTree(BSTree& bt) {
    bt.Root = NULL;
}
//=================================================================================================
int insertBSTNode(BSTNode*& root, BSTNode* p) {
    if(p == NULL) return 0;
    if(root == NULL) {
        root = p;
        return 1;
    }
    if(strcmp(root->Info.maMonHoc, p->Info.maMonHoc) == 0) return 0;
    if(strcmp(root->Info.maMonHoc, p->Info.maMonHoc) > 0) {
        insertBSTNode(root->Left, p);
    } else {
        insertBSTNode(root->Right, p);
    }
    return 1;
}
// // =================================================================================================
// void createBSTree_FromArray(BSTree& bt) {
//     ItemType a[] = {3, 2, 6, 4, 8, 5, 9, 1, 7};
//     int n = 9;
//     initBSTree(bt);
//     for(int i = 0; i<n ; i++) {
//         BSTNode* p = createBSTNode(a[i]);
//         insertBSTNode(bt.Root, p);
//     }
//     printf("\nDa them thanh cong cac phan tu tu mang vao cay NPTK.");
// }
// //=================================================================================================
// void createBSTree_Random(BSTree& bt) {
//     int n;
//     ItemType x;
//     printf("\nCho biet so nut cua cay NPTK: ");
//     scanf("%d", &n);
//     initBSTree(bt);
//     srand(time(0));
//     for(int i = 0; i<n ; i++) {
//         x = (rand()%199) - 99;
//         BSTNode* p = createBSTNode(x);
//         insertBSTNode(bt.Root, p);
//     }
//     printf("\nDa them thanh cong %d so ngau nhien vao cay NPTK", n);
// }
//=================================================================================================
void createBSTree_FromFile(BSTree& bt) {
    FILE* fi = fopen("filetxt/hocphan.txt", "rt");
    if(!fi) return;
    int n; ItemType x;
    initBSTree(bt);
    fscanf(fi, "%d\n", &n);
    for(int i = 0; i<n ; i++) {
        fscanf(fi, "%[^#]#%[^#]#%[^#]#%d#%[^\n]\n", &x.maMonHoc, &x.tenMonHoc, &x.loaiMonHoc, &x.soTC, &x.heDaoTao);
        BSTNode* p = createBSTNode(x);
        insertBSTNode(bt.Root, p);
    }
    fclose(fi);
    printf("\nDa them thanh cong cac phan tu tu file hocphan.txt vao cay NPTK.");
}
//=================================================================================================
void createBSTree_byHand(BSTree& bt) {
    int n; ItemType x;
    initBSTree(bt);
    printf("\nNhap so mon hoc muon them vao cay NPTK: ");
    scanf("%d", &n);
    getchar();
    for(int i = 0; i<n ; i++) {
        printf("Nhap thong tin mon hoc thu %d:\n", i+1);
        printf("Nhap ma mon hoc: ");
        fgets(x.maMonHoc, 16, stdin);
        printf("Nhap ten mon hoc: ");
        fgets(x.tenMonHoc, 46, stdin);
        printf("Nhap loai mon hoc: ");
        fgets(x.loaiMonHoc, 16, stdin);
        printf("Nhap so tin chi: ");
        scanf("%d", &x.soTC);
        getchar();
        printf("Nhap he dao tao: ");
        fgets(x.heDaoTao, 16, stdin);
        x.maMonHoc[strcspn(x.maMonHoc, "\n")] = 0;
        x.tenMonHoc[strcspn(x.tenMonHoc, "\n")] = 0;
        x.loaiMonHoc[strcspn(x.loaiMonHoc, "\n")] = 0;
        x.heDaoTao[strcspn(x.heDaoTao, "\n")] = 0;
        BSTNode* p = createBSTNode(x);
        insertBSTNode(bt.Root, p);
    }
    printf("\nDa them thanh cong tat ca cac mon hoc vua nhap vao cay NPTK.");
}
//=================================================================================================
void traverseNLR(BSTNode* root) {
    if(root == NULL) return;
    printf("\n%-16s%-46s%-16s%-14d%-16s", root->Info.maMonHoc, root->Info.tenMonHoc, root->Info.loaiMonHoc, root->Info.soTC, root->Info.heDaoTao);
    traverseNLR(root->Left);
    traverseNLR(root->Right);
}
//=================================================================================================
void traverseLNR(BSTNode* root) {
    if(root == NULL) return;
    traverseLNR(root->Left);
    printf("\n%-16s%-46s%-16s%-14d%-16s", root->Info.maMonHoc, root->Info.tenMonHoc, root->Info.loaiMonHoc, root->Info.soTC, root->Info.heDaoTao);
    traverseLNR(root->Right);
}
//=================================================================================================
void traverseLRN(BSTNode* root) {
    if(root == NULL) return;
    traverseLRN(root->Left);
    traverseLRN(root->Right);
    printf("\n%-16s%-46s%-16s%-14d%-16s", root->Info.maMonHoc, root->Info.tenMonHoc, root->Info.loaiMonHoc, root->Info.soTC, root->Info.heDaoTao);
}
//=================================================================================================
void traverseNRL(BSTNode* root) {
    if(root == NULL) return;
    printf("\n%-16s%-46s%-16s%-14d%-16s", root->Info.maMonHoc, root->Info.tenMonHoc, root->Info.loaiMonHoc, root->Info.soTC, root->Info.heDaoTao);
    traverseNRL(root->Right);
    traverseNRL(root->Left);
}
//=================================================================================================
void traverseRNL(BSTNode* root) {
    if(root == NULL) return;
    traverseRNL(root->Right);
    printf("\n%-16s%-46s%-16s%-14d%-16s", root->Info.maMonHoc, root->Info.tenMonHoc, root->Info.loaiMonHoc, root->Info.soTC, root->Info.heDaoTao);
    traverseRNL(root->Left);
}
//=================================================================================================
void traverseRLN(BSTNode* root) {
    if(root == NULL) return;
    traverseRLN(root->Right);
    traverseRLN(root->Left);
    printf("\n%-16s%-46s%-16s%-14d%-16s", root->Info.maMonHoc, root->Info.tenMonHoc, root->Info.loaiMonHoc, root->Info.soTC, root->Info.heDaoTao);
}
//=================================================================================================
int countBSTNode(BSTNode* root) {
    if(!root) return 0;
    int nl = countBSTNode(root->Left);
    int nr = countBSTNode(root->Right);
    return (1 + nl + nr);
}
// //=================================================================================================
// BSTNode* findBSTNode(BSTNode* root, ItemType x) {
//     if(!root) return NULL;
//     if(root->Info == x) return root;
//     else if(root->Info > x) return findBSTNode(root->Left, x);
//     else return findBSTNode(root->Right, x);
// }
// //=================================================================================================
// void NutLonHonX(BSTNode* root, ItemType x) {
//     if(!root) return;
//     NutLonHonX(root->Left, x);
//     if(root->Info > x)
//         printf("%4d", root->Info);
//     NutLonHonX(root->Right, x);
// }
// //=================================================================================================
int countBSTNodeIsLeaf(BSTNode* root) {
    if(!root) return 0;
    if(!root->Left && !root->Right) return 1;
    int nl = countBSTNodeIsLeaf(root->Left);
    int nr = countBSTNodeIsLeaf(root->Right);
    return (nl + nr);
}
//=================================================================================================
int countBSTNodeHaveOneChild(BSTNode* root) {
    if(!root) return 0;
    int nl = countBSTNodeHaveOneChild(root->Left);
    int nr = countBSTNodeHaveOneChild(root->Right);
    if((!root->Left && root->Right) || (root->Left && !root->Right))
        return (1 + nl + nr);
    else
        return (nl + nr);
}
//=================================================================================================
int countBSTNodeHaveTwoChild(BSTNode* root) {
    if(!root) return 0;
    int nl = countBSTNodeHaveTwoChild(root->Left);
    int nr = countBSTNodeHaveTwoChild(root->Right);
    if((root->Left && root->Right))
        return (1 + nl + nr);
    else
        return (nl + nr);
}
//=================================================================================================
int highTree(BSTNode* root) {
    if(!root) return 0;
    int hl = highTree(root->Left);
    int hr = highTree(root->Right);
    if(hl > hr)
        return (1 + hl);
    else
        return (1 + hr);
}
// //=================================================================================================
// int SumBSTNode(BSTNode* root) {
//     if(!root) return 0;
//     int nl = SumBSTNode(root->Left);
//     int nr = SumBSTNode(root->Right);
//     return (root->Info + nl + nr);
// }
// //=================================================================================================
// int SumBSTNodeIsLeaf(BSTNode* root) {
//     if(!root) return 0;
//     if(!root->Left && !root->Right) return root->Info;
//     int nl = SumBSTNodeIsLeaf(root->Left);
//     int nr = SumBSTNodeIsLeaf(root->Right);
//     return (nl + nr);
// }
// //=================================================================================================
// int SumBSTNodeHaveOneChild(BSTNode* root) {
//     if(!root) return 0;
//     int nl = SumBSTNodeHaveOneChild(root->Left);
//     int nr = SumBSTNodeHaveOneChild(root->Right);
//     if((!root->Left && root->Right) || (root->Left && !root->Right))
//         return (root->Info + nl + nr);
//     else
//         return (nl + nr);
// }
// //=================================================================================================
// int SumBSTNodeHaveTwoChild(BSTNode* root) {
//     if(!root) return 0;
//     int nl = SumBSTNodeHaveTwoChild(root->Left);
//     int nr = SumBSTNodeHaveTwoChild(root->Right);
//     if((root->Left && root->Right))
//         return (root->Info + nl + nr);
//     else
//         return (nl + nr);
// }
//=================================================================================================
void initSlist(SList& sl) {
    sl.Head = NULL;
    sl.Tail = NULL;
}
//=================================================================================================
int insertTail(SList& sl, SNode* p) {
    if(!p) return 0;
    if(!sl.Head) {
        sl.Head = p;
        sl.Tail = p;
    } else {
        sl.Tail->Next = p;
        sl.Tail = p;
    }
    return 1;
}
//=================================================================================================
SNode* createSNode(ItemType x) {
    SNode* p = new SNode;
    if(p == NULL) {
        printf("\nKhong du bo nho cap phat nut moi.");
        return NULL;
    }
    p->Info = x;
    p->Next = NULL;
    return p;
}
//=================================================================================================
void thongkeTheoTC(BSTNode* root, SList& sl1, SList& sl2, SList& sl3) {
    if(!root) return;
    thongkeTheoTC(root->Left, sl1, sl2, sl3);
    if(root->Info.soTC == 1) {
        SNode* p = createSNode(root->Info);
        insertTail(sl1, p);
    } else if(root->Info.soTC == 2) {
        SNode* p = createSNode(root->Info);
        insertTail(sl2, p);
    } else if(root->Info.soTC == 3) {
        SNode* p = createSNode(root->Info);
        insertTail(sl3, p);
    }
    thongkeTheoTC(root->Right, sl1, sl2, sl3);
}
//=================================================================================================
void showSlist(SList sl, int x) {
    if(!sl.Head) return;
    SNode* p = sl.Head;
    printf("\n=========================================CAC MON CO %d TIN CHI=========================================", x);
    printf("\n%-16s%-46s%-16s%-14s%-16s", "Ma mon hoc", "Ten mon hoc", "Loai mon hoc", "So tin chi", "He dao tao");
    while(p) {
        printf("\n%-16s%-46s%-16s%-14d%-16s", p->Info.maMonHoc, p->Info.tenMonHoc, p->Info.loaiMonHoc, p->Info.soTC, p->Info.heDaoTao);
        p = p->Next;
    }
}
//=================================================================================================
// void demSLtheoLoaiMonHoc(BSTNode* root, loaiMH* a, int& soLoai) {
//     if(!root) return;
//     demSLtheoLoaiMonHoc(root->Left, a, soLoai);
//     int found = 0;
// 	for (int i = 0 ; i <= soLoai ; i++) {
// 		if (strcmp(root->Info.loaiMonHoc, a[i].loai) == 0) {
// 				found = 1;
// 				a[i].SL++;
// 		}
// 	}
// 	if(found == 0) {
// 		strcpy(a[soLoai].loai, root->Info.loaiMonHoc);
// 		a[soLoai].SL = 1;
// 		soLoai++;
// 	}
//     demSLtheoLoaiMonHoc(root->Right, a, soLoai);
// }
void demSLtheoLoaiMonHoc(BSTNode* root, loaiMH* a, int& soLoai) {
    if(!root) return;
    strcpy(a[soLoai].loai, root->Info.loaiMonHoc);
    a[soLoai].SL = 1;
    int found = 0;
    for (int i = 0 ; i < soLoai ; i++) {
		if (strcmp(root->Info.loaiMonHoc, a[i].loai) == 0) {
				found = 1;
				a[i].SL++;
		}
	}
	if(found == 0) {
		soLoai++;
	}
    demSLtheoLoaiMonHoc(root->Left, a, soLoai);
    demSLtheoLoaiMonHoc(root->Right, a, soLoai);
}
//=================================================================================================
int sumTC(BSTNode* root) {
    if(!root) return 0;
    int snl = sumTC(root->Left);
    int snr = sumTC(root->Right);
    return (root->Info.soTC + snl + snr);
}
//=================================================================================================
int deleteBSTNodeX(BSTNode *&root, char x[]) {
    if (!root)
        return 0;
    if (strcmp(root->Info.maMonHoc, x) > 0)
        return deleteBSTNodeX(root->Left, x);
    else if (strcmp(root->Info.maMonHoc, x) < 0)
        return deleteBSTNodeX(root->Right, x);
    else {
        BSTNode *p = root;
        if (!root->Left) {
            root = root->Right;
            delete p;
        } else if (!root->Right) {
            root = root->Left;
            delete p;
        } else {
            BSTNode *q = findBSTNodeReplace(p);
            delete q;
        }
        return 1;
    }
}
// int deleteBSTNodeX(BSTNode *&root, char tenMH[])
// {
//     if (!root)
//         return 0;
//     if (strcmp(root->Info.tenMonHoc, tenMH) > 0)
//         return deleteBSTNodeX(root->Left, tenMH);
//     else if (strcmp(root->Info.tenMonHoc, tenMH) < 0)
//         return deleteBSTNodeX(root->Right, tenMH);
//     else if (strcmp(root->Info.tenMonHoc, tenMH) == 0)
//     {
//         BSTNode *p = root;
//         if (!root->Left)
//         {
//             root = root->Right;
//             delete p;
//         }
//         else if (!root->Right)
//         {
//             root = root->Left;
//             delete p;
//         }
//         else
//         {
//             BSTNode *q = findBSTNodeReplace(p);
//             p->Info = q->Info;                           // replace p with q
//             deleteBSTNodeX(p->Right, q->Info.tenMonHoc); // delete q
//         }
//         return 1;
//     }
// }
//=================================================================================================
BSTNode *findBSTNodeReplace(BSTNode *&p) {
    BSTNode *f = p;
    BSTNode *q = p->Right;
    while (q->Left) {
        f = q;
        q = q->Left;
    }
    p->Info = q->Info;
    if (f == p)
        f->Right = q->Right;
    else
        f->Left = q->Right;
    return q;
}
//=================================================================================================
// BSTNode *findBSTNodeTheoTenMH(BSTNode *root, char x[]) {
//     if (!root) return NULL;
//     if(strcmp(root->Info.tenMonHoc, x) == 0) return root;
//     if(root->Left)
//         return findBSTNodeTheoTenMH(root->Left, x);
//     return findBSTNodeTheoTenMH(root->Right, x);
// }
BSTNode *findBSTNodeTheoTenMH(BSTNode *root, char x[]) {
    if (!root)
        return NULL;
    if (strcmp(root->Info.tenMonHoc, x) == 0)
        return root;
    BSTNode *left = findBSTNodeTheoTenMH(root->Left, x);
    if (left)
        return left;                             // if node is found in the left subtree, return it
    return findBSTNodeTheoTenMH(root->Right, x); // else continue to search in the right subtree
}
//=================================================================================================
void nhapTTMotMonHoc(BSTree& bt) {
    ItemType x;
    getchar();
    printf("Nhap ma mon hoc: ");
    fgets(x.maMonHoc, 16, stdin);
    printf("Nhap ten mon hoc: ");
    fgets(x.tenMonHoc, 46, stdin);
    printf("Nhap loai mon hoc: ");
    fgets(x.loaiMonHoc, 16, stdin);
    printf("Nhap so tin chi: ");
    scanf("%d", &x.soTC);
    getchar();
    printf("Nhap he dao tao: ");
    fgets(x.heDaoTao, 16, stdin);
    x.maMonHoc[strcspn(x.maMonHoc, "\n")] = 0;
    x.tenMonHoc[strcspn(x.tenMonHoc, "\n")] = 0;
    x.loaiMonHoc[strcspn(x.loaiMonHoc, "\n")] = 0;
    x.heDaoTao[strcspn(x.heDaoTao, "\n")] = 0;
    BSTNode *p = createBSTNode(x);
    insertBSTNode(bt.Root, p);
}