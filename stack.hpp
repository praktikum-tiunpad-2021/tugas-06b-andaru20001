#pragma once

namespace strukdat {

namespace stack {

/**
 * @brief Node linked list berisi nilai bertipe `T` yang disimpan pada `data`
 */
template <typename T>
struct Node {
  T data;
  Node *next;
};

/**
 * @brief Tipe pointer dari node
 */
template <typename T>
using pointer = Node<T>*;

template <typename T>
using Stack = pointer<T>;

template <typename T>
Stack<T> Top;

/**
 * @brief Membuat dan menginisialisasi stack baru
 * @param Top       pointer ke puncak stack
 * 
 * @return          pointer ke puncak stack
 */
template <typename T>
Stack<T> createStack(Stack<T> Top) {
  Top = new Node<T>;
  Top->next = nullptr;
  return Top;
}

/**
 * @brief Membuat dan menginisialisasi element baru untuk dimasukan ke stack
 * @param newElement  pointer ke element baru
 * @param data        data yang akan dimasukan
 */
template <typename T>
void createElement(pointer<T>& newElement, T data) {
  newElement = new Node<T>;
  newElement->data = data;
  newElement->next = nullptr;
}

/**
 * @brief Mengambil data pada element yang berada di puncak stack
 * @param Top       pointer ke puncak stack
 * 
 * @return          data pada element puncak stack
 */
template <typename T>
T peek(Stack<T> Top) {
  return Top->next->data;
}

/**
 * @brief Mengecek apakah suatu stack kosong atau sudah mempunyai element
 * @param Top       pointer ke puncak stack
 * 
 * @return          'true' jika stack kosong dan 'false' jika stack tidak kosong
 */
template <typename T>
bool isEmpty(Stack<T> Top) {
  if (Top->next == nullptr){
    return true;
  }
  else{
    return false;
  }
}

/**
 * @brief Memasukan element ke puncak stack (push / insert first)
 * @param Top         pointer ke puncak stack
 * @param newElement  pointer ke element baru
 * 
 * @return            pointer ke puncak stack
 */
template <typename T>
Stack<T> push(Stack<T> Top, pointer<T> newElement) {
  if (Top->next == nullptr){
    Top->next = newElement;
  }
  else{
    newElement->next = Top->next;
    Top->next = newElement;
  }
  return Top;
}

/**
 * @brief Mengeluarkan element dari puncak stack (pop / delete first)
 * @param Top         pointer ke puncak stack
 * @param delElement  pointer ke element yang dihapus
 * 
 * @return            pointer ke element yang dihapus
 */
template <typename T>
Stack<T> pop(Stack<T>& Top, pointer<T> delElement) {
  if (Top->next == nullptr){
    delElement = nullptr;
  }
  else{
    delElement = Top;
    Top = Top->next;
    delElement->next = nullptr;
  }
  return delElement;
}

/**
 * @brief Mengambil element terdalam / element dasar / element terakhir pada stack
 * @note Gunakan algoritma traversal sebagai referensi
 * @param Top         pointer ke puncak stack
 * 
 * @return            pointer ke element terdalam
 */
template <typename T>
Stack<T> lastNode(Stack<T> Top) {
  if (Top->next == nullptr){
    return nullptr;
  }
  else{
    pointer<T> pHelp = Top;
    if (pHelp->next == nullptr){
      Top->next = nullptr;
      return pHelp;
    }
    else{
      pHelp = Top->next->next;
      pointer<T> temp = Top->next;
      while (pHelp->next != nullptr){
        pHelp = pHelp->next;
        temp = temp->next;
      }
      temp->next = nullptr;
      return pHelp;
    }
  }
}

}  // namespace stack

}  // namespace strukdat
