#include "stdafx.h"
#include "Gui.h"

/*##################################################################*/
/*############################# BUTTON #############################*/
/*##################################################################*/

// #### Constructor | Destructor #### //
gui::Button::Button(float x, float y, float width, float height,
	sf::Font* font, std::string text, unsigned characterSize,
	sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor,
	sf::Color outlineIdleColor, sf::Color outlineHoverColor, sf::Color outlineActiveColor,
	short unsigned id)
{
	this->keyTimeMax = 1.f;
	this->keyTime = 0.f;

	this->buttonState = BTN_IDLE;
	this->id = id;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setFillColor(idleColor);
	this->shape.setOutlineThickness(1.f);
	this->shape.setOutlineColor(outlineIdleColor);

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(textIdleColor);
	this->text.setCharacterSize(characterSize);
	this->text.setOrigin(round(this->text.getGlobalBounds().width / 2.f + this->text.getGlobalBounds().left), round(this->text.getGlobalBounds().height / 2.f + this->text.getGlobalBounds().top));
	this->text.setPosition(
		this->shape.getPosition().x + this->shape.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + this->shape.getGlobalBounds().height / 2.f
	);

	this->textIdleColor = textIdleColor;
	this->textHoverColor = textHoverColor;
	this->textActiveColor = textActiveColor;

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->outlineIdleColor = outlineIdleColor;
	this->outlineHoverColor = outlineHoverColor;
	this->outlineActiveColor = outlineActiveColor;
}

gui::Button::~Button()
{

}
// #### Constructor | Destructor #### //

// #### Accessors #### //
const bool gui::Button::getKeyTime()
{
	if (this->keyTime >= this->keyTimeMax)
	{
		this->keyTime = 0.f;
		return true;
	}
	return false;
}

const bool gui::Button::isPressed() const
{
	if (this->buttonState == BTN_ACTIVE)
		return true;
	return false;
}

const std::string gui::Button::getText() const
{
	return this->text.getString();
}

const short unsigned& gui::Button::getId() const
{
	return this->id;
}
// #### Accessors #### //

// #### Modifiers #### //
void gui::Button::updateKeyTime(const float& dt)
{
	if (this->keyTime < this->keyTimeMax)
		this->keyTime += 5.f * dt;
}

void gui::Button::setId(const short unsigned id)
{
	this->id = id;
}

void gui::Button::setText(const std::string text)
{
	this->text.setString(text);
}
// #### Modifiers #### //

// #### Functions #### //
void gui::Button::update(const sf::Vector2f& mousePos, const float& dt)
{
	this->updateKeyTime(dt);


	this->buttonState = BTN_IDLE;	// Idle

	if (this->shape.getGlobalBounds().contains(mousePos))	// Hover
	{
		this->buttonState = BTN_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->getKeyTime())	// Active
		{
			this->buttonState = BTN_ACTIVE;
		}
	}

	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->shape.setFillColor(this->idleColor);
		this->text.setFillColor(this->textIdleColor);
		this->shape.setOutlineColor(this->outlineIdleColor);
		break;
	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColor);
		this->text.setFillColor(this->textHoverColor);
		this->shape.setOutlineColor(this->outlineHoverColor);
		break;
	case BTN_ACTIVE:
		this->shape.setFillColor(this->activeColor);
		this->text.setFillColor(this->textActiveColor);
		this->shape.setOutlineColor(this->outlineActiveColor);
		break;
	default:
		this->shape.setFillColor(sf::Color::Red);
		this->text.setFillColor(sf::Color::Blue);
		this->shape.setOutlineColor(sf::Color::Green);
		break;
	}
}

void gui::Button::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
	target.draw(this->text);
}
// #### Functions #### //

/*##################################################################*/
/*############################# BUTTON #############################*/
/*##################################################################*/

/*##################################################################*/
/*############################# CHECKBOX ###########################*/
/*##################################################################*/

// #### Constructor | Destructor #### //
gui::CheckBox::CheckBox(float x, float y, float width, float height,
	sf::Font* font, unsigned characterSize,
	sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor,
	sf::Color outlineIdleColor, sf::Color outlineHoverColor, sf::Color outlineActiveColor,
	short unsigned id)
	: Button(x, y, width, height, font, "No", characterSize,
		textIdleColor, textHoverColor, textActiveColor,
		idleColor, hoverColor, activeColor,
		outlineIdleColor, outlineHoverColor, outlineActiveColor, id)
{
	this->falseStateText = "No";
	this->trueStateText = "Yes";
}

gui::CheckBox::~CheckBox()
{
}
// #### Constructor | Destructor #### //

// #### Modifiers #### //
void gui::CheckBox::switchState()
{
	if (this->checked)
		this->text.setString(this->falseStateText);
	else
		this->text.setString(this->trueStateText);

	this->checked = !this->checked;
}
// #### Modifiers #### //

// #### Accessors #### //
const bool gui::CheckBox::isChecked() const
{
	return this->checked;
}
// #### Accessors #### //

// #### Functions #### //

// #### Functions #### //

/*##################################################################*/
/*############################# CHECKBOX ###########################*/
/*##################################################################*/

/*##################################################################*/
/*########################### DROPDOWNLIST #########################*/
/*##################################################################*/

// #### Constructor | Destructor #### //
gui::DropDownList::DropDownList(float x, float y, float width, float height, sf::Font& font, std::string list[], unsigned nbOfElements, const unsigned defaultIndex)
	: font(font), showList(false), keyTimeMax(1.f), keyTime(0.f)
{
	this->activeElement = new Button(
		x, y, width, height,
		&this->font, list[defaultIndex], 14,
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	for (auto i = 0; i < nbOfElements; i++)
	{
		this->list.push_back(
			new Button(
				x, y + ((i + 1) * height), width, height,
				&this->font, list[i], 14,
				sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
				sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200),
				sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(20, 20, 20, 0), i
			)
		);
	}
}

gui::DropDownList::~DropDownList()
{
	delete this->activeElement;
	for (auto& i : this->list)
		delete i;
}
// #### Constructor | Destructor #### //


// #### Accessors #### //
const bool gui::DropDownList::getKeyTime()
{
	if (this->keyTime >= this->keyTimeMax)
	{
		this->keyTime = 0.f;
		return true;
	}
	return false;
}

const unsigned short& gui::DropDownList::getActiveElementId() const
{
	return this->activeElement->getId();
}
// #### Accessors #### //

// #### Functions #### //

void gui::DropDownList::updateKeyTime(const float& dt)
{
	if (this->keyTime < this->keyTimeMax)
		this->keyTime += 5.f * dt;
}

void gui::DropDownList::update(const sf::Vector2f& mousePos, const float& dt)
{
	this->updateKeyTime(dt);

	this->activeElement->update(mousePos, dt);

	if (this->activeElement->isPressed() && this->getKeyTime())
	{
		if (this->showList)
			this->showList = false;
		else
			this->showList = true;
	}

	if (this->showList)
		for (auto& i : this->list)
		{
			i->update(mousePos, dt);

			if (i->isPressed() && this->getKeyTime())
			{
				this->showList = false;
				this->activeElement->setText(i->getText());
				this->activeElement->setId(i->getId());
			}
		}
}

void gui::DropDownList::render(sf::RenderTarget& target)
{
	this->activeElement->render(target);

	if (this->showList)
		for (auto& i : this->list)
			i->render(target);
}
// #### Functions #### //

/*##################################################################*/
/*########################### DROPDOWNLIST #########################*/
/*##################################################################*/