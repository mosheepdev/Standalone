local item = Item("crystalis")

------------------------------------------------------------------------------------------------------------------------

function item:GetBonusDamage()
    return self:GetValue("bonus_damage")
end

------------------------------------------------------------------------------------------------------------------------

function item:GetCriticalChance()
    return self:GetValue("critical_chance")
end

function item:GetCriticalPercentage()
    return self:GetValue("critical_percentage")
end
