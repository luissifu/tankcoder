#include "MenuDrag.h"

MenuDrag::MenuDrag() {
	dragging = false;
	in_drag = false;
	mouse_x = mouse_y = 0.0f;
	original_x = original_y = 0.0f;
}

void MenuDrag::mouse_moved(float px, float py, bool pressed) {
	if (dragging)
	{
		if (pressed)
		{
			float nx = original_x - (mouse_x - px);
			float ny = original_y - (mouse_y - py);

			node->setX(nx);
			node->setY(ny);
		}
		else
		{
			dragging = false;

			std::string or_param = event.param;
			event.param = or_param + "," + std::to_string(node->getX() + node->getWidth() / 2) + "," + std::to_string(node->getY() + node->getHeight() / 2);
			events->push(event);
			event.param = or_param;

			node->setX(original_x);
			node->setY(original_y);
		}

		node->getTexture()->changeTexture(2);
	}
	else
	{
		if (pressed)
		{
			if (!in_drag && inside(px, py))
			{
				dragging = true;
				original_x = node->getX();
				original_y = node->getY();

				mouse_x = px;
				mouse_y = py;

				node->getTexture()->changeTexture(1);
			}
			else
			{
				in_drag = true;
			}
		}
		else
		{
			in_drag = false;
			node->getTexture()->changeTexture(0);
		}
	}
}

bool MenuDrag::inside(float px, float py) {
	if (px < node->getX() || px > node->getX() + node->getWidth())
		return false;

	if (py < node->getY() || py > node->getY() + node->getHeight())
		return false;

	return true;
}

