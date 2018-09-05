local item = Item("Eye_of_Skadi")

------------------------------------------------------------------------------------------------------------------------

function item:GetPassiveModifier()
    return "Eye_of_Skadi"
end

------------------------------------------------------------------------------------------------------------------------

function item:OnAttackLanded(event)
    local modifier = event.target:AddNewModifier("Eye_of_Skadi", self:GetOwner(), self)
    modifier.slow = self:GetValue("slow")
    modifier.duration = self:GetValue("slow_duration") * event.target:GetStatusResistance()
end

------------------------------------------------------------------------------------------------------------------------

local modifier = Modifier("eye_of_skadi")

------------------------------------------------------------------------------------------------------------------------

function modifier:GetBonusStrength()
    return self:GetValue("bonus_attribute_all")
end

function modifier:GetBonusAgility()
    return self:GetValue("bonus_attribute_all")
end

function modifier:GetBonusIntelligence()
    return self:GetValue("bonus_attribute_all")
end

function modifier:GetBonusCharisma()
    return self:GetValue("bonus_attribute_all")
end

------------------------------------------------------------------------------------------------------------------------

function modifier:GetProjectileParticle()
    return "projectile/eye_of_skadi"
end

------------------------------------------------------------------------------------------------------------------------

local modifier_slow = Modifier("eye_of_skadi_slow")

------------------------------------------------------------------------------------------------------------------------

function modifier_slow:GetPercentageBonusMovementSpeed()
    return self.slow
end
