#pragma once

namespace sf
{
	class RenderWindow;
}

namespace renderer
{
    class BaseRenderer
    {
	public:
		BaseRenderer(){}
		~BaseRenderer(){}
		
		
		void render(sf::RenderWindow& window);
		
	private:
    };
}
