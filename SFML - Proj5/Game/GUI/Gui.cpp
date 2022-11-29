#include "stdafx.h"
#include "Gui.h"

/*##################################################################*/
/*############################## TEXT ##############################*/
/*##################################################################*/

// #### Constructor | Destructor #### //
gui::Text::Text(float x, float y, float width, float height,
	sf::Font* font, std::string text, unsigned characterSize,
	sf::Color textColor, sf::Color containerColor, sf::Color outlineIdleColor)
{
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setFillColor(containerColor);
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

	this->textIdleColor = textColor;

	this->containerIdleColor = containerColor;

	this->outlineIdleColor = outlineIdleColor;
}

gui::Text::~Text()
{
	//delete this->font;
}
// #### Constructor | Destructor #### //

// #### Accessors #### //
const std::string gui::Text::getText() const
{
	return this->text.getString();
}

void gui::Text::setText(const std::string text)
{
	this->text.setString(text);
}
// #### Modifiers #### //

// #### Functions #### //
void gui::Text::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
	target.draw(this->text);
}
// #### Functions #### //

/*##################################################################*/
/*############################## TEXT ##############################*/
/*##################################################################*/

/*##################################################################*/
/*############################# BUTTON #############################*/
/*##################################################################*/

// #### Constructor | Destructor #### //
gui::Button::Button(float x, float y, float width, float height,
	sf::Font* font, std::string text, unsigned characterSize,
	sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
	sf::Color containerIdleColor, sf::Color hoverColor, sf::Color activeColor,
	sf::Color outlineIdleColor, sf::Color outlineHoverColor, sf::Color outlineActiveColor,
	short unsigned id)
	:	Text(x, y, width, height, font, text, characterSize, textIdleColor, containerIdleColor, outlineIdleColor)
{
	this->keyTimeMax = 1.f;
	this->keyTime = 0.f;

	this->state = IDLE;
	this->id = id;

	this->textHoverColor = textHoverColor;
	this->textActiveColor = textActiveColor;

	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

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
	if (this->state == ACTIVE)
		return true;
	return false;
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
// #### Modifiers #### //

// #### Functions #### //
void gui::Button::update(const sf::Vector2f& mousePos, const float& dt)
{
	this->updateKeyTime(dt);


	this->state = IDLE;	// Idle

	if (this->shape.getGlobalBounds().contains(mousePos))	// Hover
	{
		this->state = HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->getKeyTime())	// Active
		{
			this->state = ACTIVE;
		}
	}

	switch (this->state)
	{
	case IDLE:
		this->shape.setFillColor(this->containerIdleColor);
		this->text.setFillColor(this->textIdleColor);
		this->shape.setOutlineColor(this->outlineIdleColor);
		break;
	case HOVER:
		this->shape.setFillColor(this->hoverColor);
		this->text.setFillColor(this->textHoverColor);
		this->shape.setOutlineColor(this->outlineHoverColor);
		break;
	case ACTIVE:
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
	sf::Color containerIdleColor, sf::Color hoverColor, sf::Color activeColor,
	sf::Color outlineIdleColor, sf::Color outlineHoverColor, sf::Color outlineActiveColor,
	short unsigned id)
	: Button(x, y, width, height, font, "No", characterSize,
		textIdleColor, textHoverColor, textActiveColor,
		containerIdleColor, hoverColor, activeColor,
		outlineIdleColor, outlineHoverColor, outlineActiveColor, id)
{
	this->falseStateText = "No";
	this->trueStateText = "Yes";
}

gui::CheckBox::~CheckBox()
{
	delete this->font;
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

	for (unsigned int i = 0; i < nbOfElements; i++)
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

/*##################################################################*/
/*########################## SCROLLING VIEW ########################*/
/*##################################################################*/

// #### Constructor | Destructor #### //
gui::TextureSelector::TextureSelector(sf::RenderWindow* window, float gridSize, float x, float y, float width, float height, sf::Color containerColor, sf::Color outlineColor)
{
	this->gridSize = gridSize;

	this->selector = sf::RectangleShape(sf::Vector2f(this->gridSize, this->gridSize));
	this->selector.setOutlineThickness(2.f);
	this->selector.setFillColor(sf::Color::Transparent);

	this->view.setViewport(sf::FloatRect(x / window->getSize().x, y / window->getSize().y, width / window->getSize().x, height / window->getSize().y));

	this->view.reset(this->position);
	this->position = sf::FloatRect(x, y, width, height);

	this->background.setPosition(sf::Vector2f(x, y));
	this->background.setSize(sf::Vector2f(width, height));
	this->background.setFillColor(containerColor);
	this->background.setOutlineThickness(1.f);
	this->background.setOutlineColor(outlineColor);
}

gui::TextureSelector::~TextureSelector()
{
	if (!this->shapes.empty())
		for (auto& i : this->shapes)
			delete i.second;
}
// #### Constructor | Destructor #### //

// #### Modifiers #### //

// #### Modifiers #### //

// #### Accessors #### //

// #### Accessors #### //

void gui::TextureSelector::updateState(const sf::Vector2f& mousePos)
{
	this->mousePosGrid = sf::Vector2u(
		static_cast<unsigned>(mousePos.x) / static_cast<unsigned>(this->gridSize),
		static_cast<unsigned>(mousePos.y) / static_cast<unsigned>(this->gridSize)
	);

	this->state = IDLE;	// Idle

	if (this->background.getGlobalBounds().contains(mousePos))	// Hover
	{
		this->state = HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))	// Active
		{
			this->state = ACTIVE;
		}
	}

	switch (this->state)
	{
	case IDLE:
		this->selector.setOutlineColor(sf::Color::Transparent);
		break;
	case HOVER || ACTIVE:
		this->selector.setOutlineColor(sf::Color::Blue);
		this->selector.setPosition(this->mousePosGrid.x * this->gridSize, this->mousePosGrid.y * this->gridSize);


		std::cout << "X: " << this->mousePosGrid.x << std::endl;
		std::cout << "Y: " << this->mousePosGrid.y << std::endl;
		break;
	}
}

// #### Functions #### //
void gui::TextureSelector::update(const sf::Vector2f& mousePos, const float& dt)
{
	this->updateState(mousePos);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->position.top -= 10;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			this->position.top -= 20;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->position.top += 10;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			this->position.top += 20;
	}

	if (this->position.top < this->background.getGlobalBounds().top)
		this->position.top = this->background.getGlobalBounds().top;

	if (this->shapes["MAIN"])
		if (this->position.top > this->shapes["MAIN"]->getTexture()->getSize().y * this->shapes["MAIN"]->getScale().y - this->position.height + this->background.getPosition().y)
			this->position.top = this->shapes["MAIN"]->getTexture()->getSize().y * this->shapes["MAIN"]->getScale().y - this->position.height + this->background.getPosition().y;
}

void gui::TextureSelector::renderSelector(sf::RenderTarget& target)
{
	target.draw(this->selector);
}

void gui::TextureSelector::render(sf::RenderTarget& target)
{
	target.draw(this->background);
	target.setView(this->view);

	/* #### Render objects #### */
	if (!this->shapes.empty())
		for (auto& i : this->shapes)
			target.draw(*i.second);
	/* #### Render objects #### */

	this->renderSelector(target);

	this->view.reset(this->position);
	target.setView(target.getDefaultView());
}
// #### Functions #### //

/*##################################################################*/
/*########################## SCROLLING VIEW ########################*/
/*##################################################################*/