var itemComponent = null;
var draggedItem = null;
var startingMouse;
var posnInWindow;

function startDrag(mouse)
{
    posnInWindow = paletteItem.mapToItem(window, 0, 0);
    startingMouse = { x: mouse.x, y: mouse.y }
    loadComponent();
    // disable flicking in ListView
    listView.interactive = false;
}

//Creation is split into two functions due to an asynchronous wait while
//possible external files are loaded.

function loadComponent() {
    if (itemComponent != null) { // component has been previously loaded
        createItem();
        return;
    }

    itemComponent = Qt.createComponent("ViewItem.qml");
    if (itemComponent.status == Component.Loading)  //Depending on the content, it can be ready or error immediately
        component.statusChanged.connect(createItem);
    else
        createItem();
}

function createItem() {
    if (itemComponent.status == Component.Ready && draggedItem == null) {
        draggedItem = itemComponent.createObject(gameView,
                                                 {"image": img(picture),
                                                  "x": posnInWindow.x, "y": posnInWindow.y, "z": 3000,
                                                 "width": theScale*owidth, "height": theScale*oheight});
        //draggedItem.parent = gameView;
    } else if (itemComponent.status == Component.Error) {
        draggedItem = null;
        console.log("error creating component");
        console.log(itemComponent.errorString());
    }
}

function continueDrag(mouse)
{
    if (draggedItem == null)
        return;

    draggedItem.x = mouse.x + posnInWindow.x - startingMouse.x;
    draggedItem.y = mouse.y + posnInWindow.y - startingMouse.y;
}

function endDrag(mouse)
{
    listView.interactive = true;

    if (draggedItem == null)
        return;

    if (draggedItem.x > gameView.x
            && draggedItem.x+draggedItem.width < gameView.x+gameView.width
            && draggedItem.y > gameView.y
            && draggedItem.y+draggedItem.height < gameView.y+gameView.height
            ) { // Only drop in gameView
        draggedItem.created = true;
        draggedItem = null;
        count --;
    } else {
        draggedItem.destroy();
        draggedItem = null;
    }
}

