void findPairs (Game g) {
    list hand = g->playerArray[whoseTurn-1].playerHand;
    link card = hand->head;
    link headCard = hand->head;
    int cardVal;
    int same = TRUE;
    int count = 0;

    bubbleSort(hand);

    //Outer loop to find each set of 4
    while (card->next->next->next != NULL) {
        headCard = card;
        cardVal = card->value;
        same = TRUE;
        count = 0;

        //Inner loop to check the next three values
        while (same == TRUE && count < PAIRSIZE) {
            card = card->next;

            if (cardVal == card->value) {
                same = TRUE;
                count++;
            } else {
                same = FALSE;
            }
        }
        
        if (count == PAIRSIZE) {
            removePair (g, headCard);
        }
    }
}

static void removePair (Game g, link headCard) {
    link prev = findPre (g->playerArray[whoseTurn-1].playerHand,
    headCard);
    link curr = g->playerArray[whoseTurn-1].playerHand->head;

    if (prev == NULL) {
    }
        
}

link findPre (list l, link target) {
    link curr = l->head;
    link prev = NULL;
    int found = FALSE

    while (next != NULL && !found) {
        if (curr == target) {
            found = FALSE;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return prev;
}

void bubbleSort (list l) {
    link current = l->head;
    int listLen = listLength (l);
    int count = 0;
    
    while (count < listLen) {
        current = l->head;
        
        while (current->next != NULL) {
            if (current->value > current->next->value) {
                swap (current);
            }
        
            current = current->next;
        }
        
        count++;
    }
}

int listLength (list l) {
    link current = l->head;
    int count = 0;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}


void swap (link elt) {
    int temp;
    
    temp = elt->value;
    elt->value = elt->next->value;
    elt->next->value = temp;
}
