#pragma once

#include "Game/State/Base/State.h"

namespace gui
{
	enum states { IDLE = 0, HOVER, ACTIVE };

	/*##################################################################*/
	/*############################## TEXT ##############################*/
	/*##################################################################*/
	class Text
	{
	protected:
		// #### Variables #### //
		sf::RectangleShape shape;
		sf::Font* font;
		sf::Text text;

		sf::Color textIdleColor;

		sf::Color containerIdleColor;

		sf::Color outlineIdleColor;
		// #### Variables #### //
	public:
		// #### Constructor | Destructor #### //
		Text(float x, float y, float width, float height,
			sf::Font* font, std::string text, unsigned characterSize,
			sf::Color textColor, sf::Color containerColor,
			sf::Color outlineColor = sf::Color::Transparent);		// Class constructor
		~Text();				// Class destructor
		// #### Constructor | Destructor #### //

		// #### Accessors #### //
		const std::string getText() const;
		// #### Accessors #### //

		// #### Modifiers #### //
		void setText(const std::string text);
		// #### Modifiers #### //

		// #### Functions #### //
		void render(sf::RenderTarget& target);
		// #### Functions #### //
	};
	/*##################################################################*/
	/*############################## TEXT ##############################*/
	/*##################################################################*/

	/*##################################################################*/
	/*############################# BUTTON #############################*/
	/*##################################################################*/
	class Button
		: public Text
	{
	protected:
		// #### Variables #### //
		float keyTime;
		float keyTimeMax;

		short unsigned state;
		short unsigned id;

		sf::Color textHoverColor;
		sf::Color textActiveColor;

		sf::Color hoverColor;
		sf::Color activeColor;

		sf::Color outlineHoverColor;
		sf::Color outlineActiveColor;
		// #### Variables #### //
	public:
		// #### Constructor | Destructor #### //
		Button(float x, float y, float width, float height,
			sf::Font* font, std::string text, unsigned characterSize,
			sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
			sf::Color containerIdleColor, sf::Color hoverColor, sf::Color activeColor,
			sf::Color outlineIdleColor = sf::Color::Transparent,
			sf::Color outlineHoverColor = sf::Color::Transparent,
			sf::Color outlineActiveColor = sf::Color::Transparent,
			short unsigned id = 0);		// Class constructor
		~Button();				// Class destructor
		// #### Constructor | Destructor #### //

		// #### Accessors #### //
		const bool getKeyTime();
		const bool isPressed() const;
		const short unsigned& getId() const;
		// #### Accessors #### //

		// #### Modifiers #### //
		void updateKeyTime(const float& dt);
		void setId(const short unsigned id);
		// #### Modifiers #### //

		// #### Functions #### //
		void update(const sf::Vector2f& mousePos, const float& dt);	// Update booleans for hover and pressed
		// #### Functions #### //
	};
	/*##################################################################*/
	/*############################# BUTTON #############################*/
	/*##################################################################*/

	/*##################################################################*/
	/*############################# CHECKBOX ###########################*/
	/*##################################################################*/
	class CheckBox
		: public Button
	{
	private:
		// #### Variables #### //
		bool checked;	// If chackbox is checked
		std::string falseStateText;	// Text for false state
		std::string trueStateText;	// Text for true state
		// #### Variables #### //
	public:
		// #### Constructor | Destructor #### //
		CheckBox(float x, float y, float width, float height,
			sf::Font* font, unsigned characterSize,
			sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
			sf::Color containerIdleColor, sf::Color hoverColor, sf::Color activeColor,
			sf::Color outlineIdleColor = sf::Color::Transparent,
			sf::Color outlineHoverColor = sf::Color::Transparent,
			sf::Color outlineActiveColor = sf::Color::Transparent,
			short unsigned id = 0);		// Class constructor (textStates : {falseStateText, trueStateText})
		~CheckBox();
		// #### Constructor | Destructor #### //

		// #### Modifiers #### //
		void switchState();
		// #### Modifiers #### //

		// #### Accessors #### //
		const bool isChecked() const;
		// #### Accessors #### //

		// #### Functions #### //

		// #### Functions #### //
	};
	/*##################################################################*/
	/*############################# CHECKBOX ###########################*/
	/*##################################################################*/

	/*##################################################################*/
	/*########################### DROPDOWNLIST #########################*/
	/*##################################################################*/
	class DropDownList
	{
	private:
		// #### Variables #### //
		float keyTime;
		float keyTimeMax;

		sf::Font& font;

		gui::Button* activeElement;
		std::vector<gui::Button*> list;
		bool showList;		// Does list shows
		// #### Variables #### //
	public:
		// #### Constructor | Destructor #### //
		DropDownList(float x, float y, float width, float height, sf::Font& font, std::string list[], unsigned nbOfElements, const unsigned defaultIndex = 0);		// Class constructor
		~DropDownList();	// Class destructor
		// #### Constructor | Destructor #### //

		// #### Accessors #### //
		const bool getKeyTime();
		const unsigned short& getActiveElementId() const;
		// #### Accessors #### //

		// #### Functions #### //
		void updateKeyTime(const float& dt);
		void update(const sf::Vector2f& mousePos, const float& dt);	// Update booleans for hover and pressed
		void render(sf::RenderTarget& target);
		// #### Functions #### //
	};
	/*##################################################################*/
	/*########################### DROPDOWNLIST #########################*/
	/*##################################################################*/

	/*##################################################################*/
	/*###################### TEXT AND BUTTON LINKED ####################*/
	/*##################################################################*/
	class TextButtonLine
		: public Button
	{
	private:
		// #### Variables #### //
		
		// #### Variables #### //
	public:
		// #### Constructor | Destructor #### //
		/*TextButtonLine(float x, float y, float width, float height,
			sf::Font* font, std::string text, unsigned characterSize,
			sf::Color text_textIdleColor, sf::Color containerIdleColor,
			sf::Color outlineIdleColor = sf::Color::Transparent,
			
			float x, float y, float width, float height,
			sf::Font* font, unsigned characterSize,
			sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
			sf::Color containerIdleColor, sf::Color hoverColor, sf::Color activeColor,
			sf::Color outlineIdleColor = sf::Color::Transparent,
			sf::Color outlineHoverColor = sf::Color::Transparent,
			sf::Color outlineActiveColor = sf::Color::Transparent,
			short unsigned id = 0);*/		// Class constructor (textStates : {falseStateText, trueStateText})
		~TextButtonLine();
		// #### Constructor | Destructor #### //

		// #### Modifiers #### //
		void switchState();
		// #### Modifiers #### //

		// #### Accessors #### //
		const bool isChecked() const;
		// #### Accessors #### //

		// #### Functions #### //

		// #### Functions #### //
	};
	/*##################################################################*/
	/*###################### TEXT AND BUTTON LINKED ####################*/
	/*##################################################################*/

	/*##################################################################*/
	/*########################## SCROLLING VIEW ########################*/
	/*##################################################################*/
	class TextureSelector
	{
	private:
		// #### Variables #### //
		sf::View view;
		sf::FloatRect position;	// Camera position
		
		// #### Variables #### //

		// #### Init function #### //
		
		// #### Init function #### //
	public:
		// #### Variables #### //
		unsigned short state;

		sf::RectangleShape background;
		std::map<std::string, sf::Sprite*> shapes;	// Textures list

		sf::Vector2u mousePosGrid;
		float gridSize;

		sf::RectangleShape selector;
		// #### Variables #### //

		// #### Constructor | Destructor #### //
		TextureSelector(sf::RenderWindow* window, float gridSize,
			float x, float y, float width, float height,
			sf::Color containerColor = sf::Color(0, 0, 0, 127), sf::Color outlineColor = sf::Color::Transparent);	// Class constructor
		~TextureSelector();
		// #### Constructor | Destructor #### //

		// #### Modifiers #### //
		
		// #### Modifiers #### //

		// #### Accessors #### //
		
		// #### Accessors #### //

		// #### Functions #### //
		void updateState(const sf::Vector2f& mousePos);
		void update(const sf::Vector2f& mousePos, const float& dt);

		void renderSelector(sf::RenderTarget& target);
		void render(sf::RenderTarget& target);
		// #### Functions #### //
	};
	/*##################################################################*/
	/*########################## SCROLLING VIEW ########################*/
	/*##################################################################*/
}